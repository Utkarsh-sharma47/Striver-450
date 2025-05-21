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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // length = 1
    if (head->next == NULL)
        return nullptr;

    int len = 1;
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    int t = len - n + 1;

    if (t == 1)
    {
        return head->next;
    }

    temp = head;
    int idx = 1;
    while (idx < t - 1)
    {
        idx++;
        temp = temp->next;
    }

    ListNode *del = temp->next;
    temp->next = temp->next->next;
    delete (del);

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
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    // head->next->next->next = new ListNode(4);
    //  head->next->next->next->next = new ListNode(5);

    ListNode *temp = removeNthFromEnd(head, 3);
    printList(temp);

    return 0;
}
