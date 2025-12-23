// Given the beginning of a singly linked list head, reverse the list,
// and return the new beginning of the list.
// You should aim for a solution with O(n) time and O(1) space,
// where n is the length of the given list.

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return head;

        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nextTmp = head->next;

        while (curr != nullptr)
        {
            nextTmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTmp;
        }

        return curr;
    }
};
