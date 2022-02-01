#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr) {}
    ListNode (int val, ListNode *next): val(val), next(next) {}
};

class Solution{
    public:
        ListNode *removeElements(ListNode *head, int val){
            ListNode *prev = nullptr, *current = head;

            while(current){
                if(current->val == val && prev == nullptr)
                    head = current->next;
                if(current->val == val && prev)
                    prev->next = current->next;
                if(current->val != val)
                    prev = current;
                
                current = current->next;
            }


            return head;
        }
};