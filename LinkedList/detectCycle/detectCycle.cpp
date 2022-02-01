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
    ListNode *detectCycle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        bool hasCycle = false;
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                break;
        }

        if(slow != fast) return nullptr;

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};