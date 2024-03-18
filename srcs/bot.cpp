#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <csignal>

#include "../includes/Parsing.hpp"

int	servSocket = -1;

void	sighandler(int signum)
{
	if (signum != SIGINT)
		return ;
	std::string msg = "QUIT :bot quit\r\n";
	send(servSocket, msg.c_str(), msg.length(), 0);
	close(servSocket);
}

int	connectBot(char **av)
{
	int servSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (servSocket == -1)
	{
		perror("Server socket");
		return (-1);
	}

	sockaddr_in serverAddress;
	std::memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(std::atoi(av[1]));
	inet_pton(AF_INET, "localhost", &serverAddress.sin_addr);

	if (connect(servSocket, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1)
	{
		perror("Server");
		close(servSocket);
		return (-1);
	}
	
	std::string	msg = "PASS " + std::string(av[2]) + "\r\n";
	send(servSocket, msg.c_str(), msg.length(), 0);
	msg = "USER BOT\r\n";
	send(servSocket, msg.c_str(), msg.length(), 0);
	msg = "NICK bot\r\n";
	send(servSocket, msg.c_str(), msg.length(), 0);

	return (servSocket);
}

void	safeQuote(std::string &cmd)
{
	size_t	pos = cmd.find("\'");

	while (pos != cmd.npos)
	{
		cmd.replace(pos, 1, "\'\'");
		pos += 3;
		pos = cmd.find("\'", pos);
	}

	pos = cmd.find("\"");

	while (pos != cmd.npos)
	{
		cmd.replace(pos, 1, "\\\"");
		pos += 2;
		pos = cmd.find("\"", pos);
	}
}

std::string	callAI(std::string msg)
{
	std::string cmd = msg.substr(msg.find(":", 1) + 1);

	if (cmd.find("\r") != cmd.npos)
		cmd.erase(cmd.find("\r"));

	safeQuote(cmd);

	std::string	call =  "curl --location --insecure --request POST 'https://api.openai.com/v1/chat/completions' \
--header 'Authorization: Bearer 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' \
--header 'Content-Type: application/json' \
--data-raw '{ \"model\": \"gpt-3.5-turbo\", \"messages\": [{\"role\": \"user\", \"content\": \"" + cmd + "\"}]}' > answer.json";

	system(call.c_str());

	std::ifstream answer("answer.json", std::ifstream::in);

	if (!answer.is_open())
		return ("call failed");

	std::string	line;

	while (answer && line.find("content") == line.npos)
		std::getline(answer, line);
	answer.close();

	if (line.find("content") == line.npos)
		return ("Request error");

	line = line.substr(line.find(":") + 2);

	return (line);
}

void	sendResponse(std::string cmd, std::string response, int servSocket)
{
	std::string target;
	if (cmd.find(":") != cmd.npos && cmd.find(" ") != cmd.npos)
		target = cmd.substr(cmd.find(":") + 1, cmd.find(" ") - 1);

	std::string	msg = "PRIVMSG " + target + " :" + response + "\r\n";
	send(servSocket, msg.c_str(), msg.length(), 0);
}

bool	isCall(std::string str)
{
	std::string	cmd;
	if (str.find(" ") != str.npos)
		cmd = str.substr(str.find(" ") + 1);
	if (cmd.find(" ") != cmd.npos)
		cmd = cmd.substr(0, cmd.find(" "));

	if (cmd == "PRIVMSG")
		return (true);

	return (false);
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Error: wrong number of arguments." << std::endl;
		std::cout << "Usage: ./ircbot <port> <password>" << std::endl;
		return (1);
	}
	servSocket = connectBot(av);
	if (servSocket == -1)
		return (-1);

	signal(SIGINT, sighandler);

	while (true)
	{
		std::string	stock;
		char buf[1024];
		std::memset(buf, 0, sizeof(buf));
		ssize_t bytesRead = recv(servSocket, buf, sizeof(buf), 0);

		if (bytesRead <= 0)
		{
			std::cerr << "SIGINT or recv error or disconnected from server\n";
			break;
		}
		else
		{
			stock += buf;
			if (stock.find("\r\n") != std::string::npos && isCall(stock))
			{
				std::string response = callAI(stock);
				sendResponse(stock, response, servSocket);
				stock.clear();
			}
			else if (stock.find("\r\n") != std::string::npos)
				stock.clear();
		}
	}

	std::string msg = "QUIT :bot quit\r\n";
	send(servSocket, msg.c_str(), msg.length(), 0);
	close(servSocket);

	return (0);
}
