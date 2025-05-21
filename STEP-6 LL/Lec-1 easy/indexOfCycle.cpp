/*
Given the head of a linked list, return the node where the cycle
begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in
the list that can be reached again by continuously following the
next pointer. Internally, pos is used to denote the index of the
node that tail's next pointer is connected to (0-indexed).
It is -1 if there is no cycle.
Note that pos is not passed as a parameter.
*/

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

ListNode *detectCycle(ListNode *head)
{
    if (!head || !head->next)
        return nullptr;

    ListNode *slow = head;
    ListNode *fast = head;

    // Detect if a cycle exists
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // Found cycle, now find starting node
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // cycle start node
        }
    }

    return nullptr; // no cycle
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
    printList(head);

    // Don't forget to free memory if needed
    return 0;
}
