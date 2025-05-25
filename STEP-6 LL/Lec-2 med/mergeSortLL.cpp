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

// -------------------------------------------------------------

ListNode *mid(ListNode *head)
{
    ListNode *s = head;
    ListNode *f = head;
    while (f->next && f->next->next)
    {
        s = s->next;
        f = f->next->next;
    }
    return s;
}
ListNode *merge(ListNode *l, ListNode *r)
{
    ListNode *t1 = l;
    ListNode *t2 = r;
    ListNode *dum = new ListNode(-1);
    ListNode *temp = dum;
    temp->next = NULL;

    while (t1 && t2)
    {
        if (t1->val < t2->val)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    // link the remaining linked list to final L
    if (t1)
        temp->next = t1;
    else
        temp->next = t2;

    return dum->next;
}
ListNode *mergeSort(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *m = mid(head);
    ListNode *right = m->next;
    m->next = NULL; // Split before recursive calls

    ListNode *leftSorted = mergeSort(head);
    ListNode *rightSorted = mergeSort(right);

    return merge(leftSorted, rightSorted);
}

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    else if (head->next->next == NULL)
    {
        if (head->next->val < head->val)
        {
            int temp = head->val;
            head->val = head->next->val;
            head->next->val = temp;
        }
        return head;
    }
    else
    {
        return mergeSort(head);
    }
}

// -------------------------------------------------------------

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
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);

    printList(head);
    
    printList(sortList(head));

    // Don't forget to free memory if needed
    return 0;
}
