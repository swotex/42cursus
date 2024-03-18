#include "../includes/Exception.hpp"

const char* ServerSocketException::what() const throw()
{
	return ("Error: cannot create server socket.");
}

const char* ServerBindingException::what() const throw()
{
	return ("Error: cannot bind server socket.");
}

const char* ServerListenException::what() const throw()
{
	return ("Error: cannot listen on server socket.");
}

const char* SocketOptException::what() const throw()
{
	return (strerror(errno));
}
