// Design a stack class that supports the push, pop, top, and getMin operations.
// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// Each function should run in O(1) time.
// You should aim for a solution with O(1) time for each function call and O(n) space,
//  where n is the maximum number of elements present in the stack.
//  It is guaranteed that pop, top, and getMin will always be called on non-empty stacks.

#include <utility>
#include <vector>
class MinStack
{
private:
    std::vector<std::pair<int, int>> stack_;

public:
    MinStack() = default;

    // O(1) since vector insertion at the end is amortized O(1)
    void push(int val)
    {
        if (stack_.empty()){
            stack_.emplace_back(val, val);
        } else {
            val < stack_.back().second ? stack_.emplace_back(val, val) : stack_.emplace_back(val, stack_.back().second); 
        }
    }
    // O(1) since vector removal at the end is amortized O(1)
    void pop()
    {
        stack_.pop_back();
    }

    int top()
    {
        return stack_.back().first;
    }

    int getMin()
    {
        return stack_.back().second;
    }
};

int main()
{
}