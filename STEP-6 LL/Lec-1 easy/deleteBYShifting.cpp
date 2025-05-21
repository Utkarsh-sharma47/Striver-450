#include <iostream>
using namespace std;

// Definition for singly-linked list (LeetCode format)
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void deleteNodeByShifting(ListNode *node)
{
    ListNode *temp = node;
    while (temp->next->next != NULL)
    {
        temp->val = temp->next->val;
        temp = temp->next;
    }
    temp->val = temp->next->val;
    temp->next = NULL;
    delete (temp->next);
    return;
}

// Function to print the linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Example: creating a linked list with values 1 -> 2 -> 3 -> 4 -> 5
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    printList(head);
    deleteNodeByShifting(head->next);
    printList(head);

    // Don't forget to free memory if needed
    return 0;
}
