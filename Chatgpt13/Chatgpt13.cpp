// Chatgpt13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ChatGptObj.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA w = {};
	WSAStartup(MAKEWORD(2, 2), &w);
	CHATGPT_API c("your-api-key");
	c.SetModel("text-ada-001");
	for (;;)
	{
		std::string input;
		std::cout << "Enter question:";
		std::getline(std::cin, input);
		if (input.empty())
			break;
		auto off = c.Text(input.c_str());
		if (!off.has_value())
			continue;
		auto& r = off.value();
		std::cout << r.t << std::endl;
	}
}

