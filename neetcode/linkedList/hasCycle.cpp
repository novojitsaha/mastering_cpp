// Given the beginning of a linked list head, return true if there
// is a cycle in the linked list. Otherwise, return false.
// There is a cycle in a linked list if at least one node in the
// list can be visited again by following the next pointer.

// You should aim for a solution with O(n) time and O(1) space,
// where n is the length of the given list.

struct ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

bool hasCycle(ListNode *head)
{
    // fast and slow pointer technique

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}