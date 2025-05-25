#include <bits/stdc++.h>
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // Dummy node acts as the starting point of the result list
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy; // Pointer to build the new list
    int carry = 0;          // Carry to hold any overflow

    // Loop until both lists are exhausted and there's no carry
    while (l1 || l2 || carry)
    {
        int sum = carry; // Start with the carry from previous addition

        // If l1 is not null, add its value to sum and move to next node
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        // If l2 is not null, add its value to sum and move to next node
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        // Update carry for next iteration (e.g. 17 => carry = 1)
        carry = sum / 10;

        // Create a new node with the digit part of sum (e.g. 17 => 7)
        curr->next = new ListNode(sum % 10);

        // Move the current pointer forward
        curr = curr->next;
    }

    // Return the next of dummy node which is the actual head of the result list
    return dummy->next;
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
