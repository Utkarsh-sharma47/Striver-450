#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int,ListNode*>>> pq;
        //add all heads in linked list- <<value, node>> as pair
        for(int i=0; i<lists.size(); i++)
        {
           if(lists[i]!=NULL)
           {
                pq.push({lists[i]->val, lists[i]});
           }
        }

        //make a new node
        ListNode* dummy=new ListNode(-1); //
        ListNode* temp=dummy;
        while(!pq.empty())
        {
            pair<int,ListNode*> p = pq.top();//take the smallest
            pq.pop(); //pop it after extracting
            ListNode* x=p.second;
            
            temp->next=x;
            temp=temp->next;

            if(x->next != NULL) pq.push({x->next->val, x->next});
        }
        return dummy->next;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& arr) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    for (int val : arr) {
        temp->next = new ListNode(val);
        temp = temp->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: merge 3 sorted linked lists
    vector<ListNode*> lists;
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    Solution sol;
    ListNode* result = sol.mergeKLists(lists);
    cout << "Merged List: ";
    printList(result);

    return 0;
}
