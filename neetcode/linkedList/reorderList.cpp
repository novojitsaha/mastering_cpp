// Reorder Linked List
// You are given the head of a singly linked-list.
// Reorder the nodes of the linked list to be in this
// order [0, n-1, 1, n-2, 2, n-3, ...] where n = length of
// the list.
// You should aim for a solution with O(n) time and O(1) space,
// where n is the length of the given list.

struct ListNode
{
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int val) : val(val), next(nullptr) {};
    ListNode(int val, ListNode *next) : val(val), next(next) {};
};

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr)
    {
        ListNode *nextTmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTmp;
    }
    return prev;
}

void reorderList(ListNode *head)
{

    if (!head || !head->next)
    {
        return;
    }

    // use fast and slow pointer to find midpoint
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow now points to midpoint.
    ListNode *curr = head;
    ListNode *secondHalf = slow->next;
    secondHalf = reverseList(secondHalf);
    slow->next = nullptr;
    while (secondHalf)
    {

        ListNode *tmp1 = curr->next;
        ListNode *tmp2 = secondHalf->next;

        curr->next = secondHalf;
        secondHalf->next = tmp1;

        curr = tmp1;
        secondHalf = tmp2;
    }
}
