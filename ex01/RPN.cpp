#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(RPN& copy)
{
	*this = copy;
}

static void	ft_operate(std::stack<int>& tokens, char c)
{
	int	num2 = tokens.top();
	tokens.pop();

	int	num1 = tokens.top();
	tokens.pop();

	switch (c)
	{
		case '/':
			tokens.push(num1 / num2);
			break;
		case '+':
			tokens.push(num1 + num2);
			break;
		case '-':
			tokens.push(num1 - num2);
			break;
		default:
			tokens.push(num1 * num2);
			break;
	}
}

RPN::RPN(char* line)
{
	int	num;

	while(*line)
	{
		while (*line && *line == ' ')
			line++;
		if (!(*line))
			break;
		if (std::isdigit(*line))
		{
			num = std::atoi(line);
			_tokens.push(num);
		}
		else
		{
			ft_operate(_tokens, *line);
		}
		while (*line && *line != ' ')
			line++;
	}
}

RPN::~RPN()
{

}

RPN&	RPN::operator=(RPN& copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}

int	RPN::top()
{
	return _tokens.top();
}