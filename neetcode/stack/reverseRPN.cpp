// You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.
// Return the integer that represents the evaluation of the expression.
// The operands may be integers or the results of other operations.
// The operators include '+', '-', '*', and '/'.
// Assume that division between integers always truncates toward zero.
// Input: tokens = ["1","2","+","3","*","4","-"]
// Output: 5
// Explanation: ((1 + 2) * 3) - 4 = 5
// You should aim for a solution with O(n) time and O(n) space, where n is the size of the input array.

#include <vector>
#include <string>
#include <stack>
class Solution
{
public:
    int reverseRPN(std::vector<std::string> &tokens)
    {
        std::stack<int> stack;

        for (const std::string &s : tokens)
        {
            if (s == "+")
            {
                int top = stack.top();
                stack.pop();
                int bottom = stack.top();
                stack.pop();
                int operand = top + bottom;
                stack.emplace(operand);
            }
            else if (s == "-")
            {
                int top = stack.top();
                stack.pop();
                int bottom = stack.top();
                stack.pop();
                int operand = bottom - top;
                stack.emplace(operand);
            }
            else if (s == "*")
            {
                int top = stack.top();
                stack.pop();
                int bottom = stack.top();
                stack.pop();
                int operand = top * bottom;
                stack.emplace(operand);
            }
            else if (s == "/")
            {
                int top = stack.top();
                stack.pop();
                int bottom = stack.top();
                stack.pop();
                int operand = bottom / top;
                stack.emplace(operand);
            }
            else
            {
                int val = std::stoi(s);
                stack.emplace(val);
            }
        }
        return stack.top();
    }
};

int main()
{
}
