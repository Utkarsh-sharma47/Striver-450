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

int length(ListNode *head)
{
    if (!head)
        return 0;
    int len = 1;
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

// -----------------------------------------------------------------------

// Helper function to get the k-th node from the current node
ListNode *getKthNode(ListNode *temp, int k)
{
    k -= 1; // because we include the current node as the 1st
    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp; // returns NULL if fewer than k nodes left
}

// Function to reverse a linked list from a given head pointer
void reverseLinkedList(ListNode *&head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

// Main function to reverse linked list in groups of size k
ListNode *kReverse(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *prevLast = NULL; // keeps track of the last node of previous reversed block

    while (temp != NULL)
    {
        ListNode *kThNode = getKthNode(temp, k); // get the k-th node from temp
        if (kThNode == NULL)
        {
            // Not enough nodes left for a full k-group
            if (prevLast)
                prevLast->next = temp;
            break;
        }

        ListNode *nextNode = kThNode->next; // store the (k+1)th node
        kThNode->next = NULL;              // disconnect k-th node from rest of the list

        // Reverse the k-sized block starting at temp
        reverseLinkedList(temp);

        // Link previous part of list to new head of this block
        if (temp == head)
        {
            head = kThNode; // this is the new head of the entire list
        }
        else
        {
            prevLast->next = kThNode;
        }

        // Move prevLast to the tail of this reversed block
        prevLast = temp;

        // Move temp to the next block
        temp = nextNode;
    }

    return head; // return new head after all reversals
}

// -----------------------------------------------------------------------

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
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printList(head);

    printList(kReverse(head, 2)); // ✅ fixed: call the correct function

    // Don't forget to free memory if needed
    return 0;
}
