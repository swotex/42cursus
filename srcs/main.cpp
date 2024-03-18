#include <csignal>
#include "../includes/Server.hpp"

int	g_stop = 0;

int	checkPort(char *port)
{
	int	entryPort;

	if (port == NULL || port[0] == 0)
		return (1);
	for (size_t i = 0; i < strlen(port); i++)
	{
		if (isdigit(port[i]) == 0)
			return (2);
	}
	if (strlen(port) > 5)
		return (3);
	entryPort = atoi(port);
	if (entryPort == 0 || entryPort > 65535)
		return (3);
	if (entryPort <= 1023)
		return (4);
	return (0);
}

int	optionVerify(char *port, char *password)
{
	switch (checkPort(port))
	{
		case 1:
			std::cout << "Error: port option can't be null or empty" << std::endl;
			return (1);

		case 2:
			std::cout << "Error: port option isn't a number" << std::endl;
			return (1);

		case 3:
			std::cout << "Error: port option is invalid. The port range is 1-65535" << std::endl;
			return (1);

		case 4:
			std::cout << "Warning: ports in range 1-1023 are the privileged ones. An application needs to be run as root in order to listen to these ports." << std::endl;
			return (1);

		default:
			break;
	}
	if (password == NULL || password[0] == 0)
	{
		std::cout << "Error: password can't be null or empty" << std::endl;
		return (1);
	}
	return (0);
}

void	sigHandler(int sigNum)
{
	if (sigNum == SIGINT)
		g_stop = 1;
}

int		main (int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Error: wrong number of arguments." << std::endl;
		std::cout << "Usage: ./ircserv <port> <password>" << std::endl;
		return (1);
	}

	if (optionVerify(av[1], av[2]) != 0)
		return (1);

	g_stop = 0;
	std::signal(SIGINT, sigHandler);

	try
	{
		Server server(av[1], av[2]);
		server.clienthandler();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
