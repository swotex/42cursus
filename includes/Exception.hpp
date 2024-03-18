#pragma once

#include <exception>
#include <cstring>
#include <cerrno>
#include <iostream>

class ServerSocketException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class ServerBindingException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class ServerListenException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class SocketOptException : public std::exception
{
	public:
		virtual const char* what() const throw();
};
