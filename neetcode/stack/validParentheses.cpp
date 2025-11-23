// You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.
// The input string s is valid if and only if:
// Every open bracket is closed by the same type of close bracket.
// Open brackets are closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
// Return true if s is a valid string, and false otherwise.
// You should aim for a solution with O(n) time and O(n) space, where n is the length of the given string.

#include <string>
#include <iostream>
#include <stack>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> charStack;

        for (const char &c : s)
        {
            switch (c)
            {
            case '(':
                charStack.push(c);
                break;
            case ')':
                if (charStack.empty())
                    return false;
                if (charStack.top() == '(')
                {
                    charStack.pop();
                }
                else
                {
                    return false;
                }
                break;
            case '{':
                charStack.push(c);
                break;
            case '}':
                if (charStack.empty())
                    return false;
                if (charStack.top() == '{')
                {
                    charStack.pop();
                }
                else
                {
                    return false;
                }
                break;

            case '[':
                charStack.push(c);
                break;
            case ']':
                if (charStack.empty())
                    return false;
                if (charStack.top() == '[')
                {
                    charStack.pop();
                }
                else
                {
                    return false;
                }
                break;
            }
        }
        if (charStack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
}