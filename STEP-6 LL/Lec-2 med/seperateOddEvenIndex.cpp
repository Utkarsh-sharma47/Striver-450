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

ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next)
        return head; // len =0/1
    if (!head->next->next)
        return head; // len 2

    ListNode *odd = head;
    ListNode *oddlast;
    ListNode *even = head->next;
    ListNode *evenstart = head->next;

    while (odd && odd->next && even && even->next)
    {
        ListNode *oddprev = odd;
        ListNode *evenprev = even;
        odd = odd->next->next;
        even = even->next->next;

        // link odd and oddprev and even with evenprev
        oddprev->next = odd;
        oddlast = odd;
        evenprev->next = even;
    }
    // join odd last to even start
    oddlast->next = evenstart;
    return head;
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

    // Don't forget to free memory if needed
    return 0;
}
