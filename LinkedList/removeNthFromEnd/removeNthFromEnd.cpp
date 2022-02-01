#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution{
    public:

        ListNode *removeNthFromEnd(ListNode *head, int n){
            ListNode *start = head;
            ListNode *fromEndNode = nullptr;

            if(head->next == nullptr && n == 1)
            {
                head = head->next;
                return head;
            }

            while(start != nullptr){
                if(fromEndNode != nullptr)
                    fromEndNode = fromEndNode->next;
                if(n-- == 0)
                    fromEndNode = head;
                start = start->next;
            }

            /* when the node to be removed is head node */
            if(fromEndNode == nullptr){
                head = head->next;
            }else{
                fromEndNode->next = fromEndNode->next->next;
            }            
            
            return head;
        }
};