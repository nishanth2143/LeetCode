#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fp = head;
        ListNode* sp = head;
        if(head == nullptr)
            return false;
            
        while(fp != NULL && fp->next != NULL){
            sp = sp->next;
            fp = fp->next->next;
            if(fp == sp)
                return true;
            
        }

        return false;
    }
};