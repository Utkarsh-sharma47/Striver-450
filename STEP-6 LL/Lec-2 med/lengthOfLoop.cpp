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

int lengthOfLoop(ListNode *head)
{
    if (!head || !head->next)
        return 0;

    ListNode *slow = head;
    ListNode *fast = head;

    // Step 1: Detect if a cycle exists
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // Step 2: Found cycle. Count its length.
            int len = 1;
            fast = fast->next;
            while (fast != slow)
            {
                fast = fast->next;
                len++;
            }
            return len;
        }
    }

    return 0; // No cycle
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
    ListNode* temp =head->next->next;
    temp->next=head;

   
    cout<<lengthOfLoop(head);
    

    // Don't forget to free memory if needed
    return 0;
}
