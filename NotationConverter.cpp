// Nuva Shrestha
// Vaibhavi Patel
#include "NotationConverter.hpp"
#include "Deque.hpp"
#include <stdexcept>

inline int precedence(char val)
{
    if (val == '+' || val == '-')
    {
        return 1;
    }
    else if (val == '*' || val == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

class NotationConverter : public NotationConverterInterface
{
public:
    std::string postfixToInfix(std::string inStr) override
    {
        DequeDLL expressionDeque;
        for (size_t i = 0; i < inStr.size(); i++)
        {
            char ch = inStr[i];
            if (ch == ' ')
            {
                continue;
            }
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            {
                std::string operand(1, ch);
                expressionDeque.pushBack(operand);
            }
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                std::string operand2 = " " + expressionDeque.back();
                expressionDeque.popBack();
                std::string operand1 = expressionDeque.back() + " ";
                expressionDeque.popBack();
                std::string infixExpression = "(" + operand1 + ch + operand2 + ")";
                expressionDeque.pushBack(infixExpression);
            }
        }
        return expressionDeque.back();
    }

    std::string postfixToPrefix(std::string inStr) override
    {
        DequeDLL expressionDeque;
        for (size_t i = 0; i < inStr.size(); i++)
        {
            char ch = inStr[i];
            if (ch == ' ')
            {
                continue;
            }
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            {
                std::string operand(1, ch);
                expressionDeque.pushFront(operand);
            }
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                std::string operand2 = ' ' + expressionDeque.front();
                expressionDeque.popFront();
                std::string operand1 = ' ' + expressionDeque.front();
                expressionDeque.popFront();
                std::string prefixExpression = ch + operand1 + operand2;
                expressionDeque.pushFront(prefixExpression);
            }
        }
        return expressionDeque.front();
    }

    std::string infixToPostfix(std::string inStr) override
    {
        DequeDLL expressionDeque;
        std::string postfix;
        for (char ch : inStr)
        {
            if (ch == ' ')
                continue;
            if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')))
            {
                postfix += ch;
                postfix += ' ';
            }
            else if (ch == '(')
            {
                expressionDeque.pushFront(std::string(1, ch));
            }
            else if (ch == ')')
            {
                while (!expressionDeque.empty() && expressionDeque.front() != "(")
                {
                    postfix += expressionDeque.front();
                    postfix += ' ';
                    expressionDeque.popFront();
                }

                if (!expressionDeque.empty() && expressionDeque.back() == "(")
                    expressionDeque.popFront(); // Remove the opening parenthesis from deque
            }
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                while (!expressionDeque.empty() && precedence(ch) <= precedence(expressionDeque.front()[0]))
                {
                    postfix += expressionDeque.front();
                    expressionDeque.popFront();
                    postfix += ' ';
                }
                expressionDeque.pushFront(std::string(1, ch)); // Push current operator to deque
            }
        }

        while (!expressionDeque.empty())
        {
            postfix += expressionDeque.front();
            expressionDeque.popFront();
            postfix += ' ';
        }

        return postfix;
    }

    std::string infixToPrefix(std::string inStr) override
    {
        DequeDLL expressionDeque;
        std::string prefix = "";
        bool firstOperand = true; // Flag to indicate if it's the first operand

        for (int i = inStr.size() - 1; i >= 0; i--)
        {
            char ch = inStr[i];
            if (ch == ' ')
            {
                continue;
            }
            if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')))
            {
                if (!firstOperand)
                {
                    prefix = " " + prefix;
                }
                prefix = ch + prefix;
                firstOperand = false; // Set the flag to false after the first operand
            }
            else if (ch == ')')
            {
                expressionDeque.pushFront(std::string(1, ch));
            }
            else if (ch == '(')
            {
                while (!expressionDeque.empty() && expressionDeque.front()[0] != ')')
                {
                    prefix = expressionDeque.front() + ' ' + prefix;
                    expressionDeque.popFront();
                }
                expressionDeque.popFront();
            }
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                while (!expressionDeque.empty() && precedence(ch) <= precedence(expressionDeque.front()[0]))
                {
                    prefix = expressionDeque.front() + prefix;
                    expressionDeque.popFront();
                }
                expressionDeque.pushFront(std::string(1, ch));
            }
        }
        while (!expressionDeque.empty())
        {
            prefix = expressionDeque.front() + prefix;
            expressionDeque.popFront();
        }
        return prefix;
    }

    std::string prefixToInfix(std::string inStr) override
    {
        DequeDLL expressionDeque;
        for (int i = inStr.size() - 1; i >= 0; i--)
        {
            char ch = inStr[i];
            if (ch == ' ')
                continue;
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            {
                std::string operand(1, ch);
                expressionDeque.pushFront(operand);
            }
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                std::string operand1 = expressionDeque.front() + " ";
                expressionDeque.popFront();
                std::string operand2 = " " + expressionDeque.front();
                expressionDeque.popFront();
                std::string infixExpression = "(" + operand1 + ch + operand2 + ")";
                expressionDeque.pushFront(infixExpression);
            }
        }
        return expressionDeque.front();
    }

    std::string prefixToPostfix(std::string inStr) override
    {
        DequeDLL expressionDeque;
        for (int i = inStr.size() - 1; i >= 0; i--)
        {
            char ch = inStr[i];
            if (ch == ' ')
            {
                continue;
            }

            if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')))
            {
                std::string operand(1, ch);
                expressionDeque.pushFront(operand);
            }

            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                std::string operand2 = expressionDeque.front() + ' ';
                expressionDeque.popFront();
                std::string operand1 = expressionDeque.front() + ' ';
                expressionDeque.popFront();
                std::string expresionPostfix = operand2 + operand1 + ch;
                expressionDeque.pushFront(expresionPostfix);
            }
        }
        return expressionDeque.front();
    }
};