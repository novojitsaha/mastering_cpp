// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted linked list and return the head
//  of the new sorted linked list. The new list should be made up of
//  nodes from list1 and list2.

// You should aim for a solution with O(n + m) time and O(1) space,
// where n is the length of list1 and m is the length of list2.

struct ListNode
{

public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummyNode = new ListNode();
    ListNode *curr = dummyNode;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    if (list1)
    {
        curr->next = list1;
    }
    else if (list2)
    {
        curr->next = list2;
    }
    return dummyNode->next;
}