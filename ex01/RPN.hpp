#pragma once
#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int>	_tokens;
	public:
		RPN();
		RPN(RPN& copy);
		RPN(char* line);
		~RPN();
		RPN&	operator=(RPN& copy);
		int		top();
};