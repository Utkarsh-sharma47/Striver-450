/*
Q. return the point where 2 linked list meet 
   solve in O(n+m) time and O(1) space
*/
#include <bits/stdc++.h>
using namespace std;

/*
- travse both linked list with pointer t1, t2
- if t1->next==NULL  then t1=head2;
- if t2->next==NULL  then t2=head1;
-keep of traversng until t1==t2

by this eventually t1 nd t2 will start from same lenght
 
*/

// Definition for singly-linked list (LeetCode format)
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if(!head1 || !head2) return nullptr;
        ListNode* t1=head1;
        ListNode* t2=head2;
        bool b1=true, b2=true;
        while(t1 && t2)
        {
            if(t1==t2) return t1;
            
            if(t1->next==NULL && b1) {b1=0;t1=head2;}
            if(t2->next==NULL & b2) {t2=head1; b2=0;}

            t1=t1->next;
            t2=t2->next;
        }
        return nullptr;
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
    

    // Don't forget to free memory if needed
    return 0;
}
