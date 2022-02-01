#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution{
    public:
        ListNode* rotateRight(ListNode* head, int k){
            if(head == nullptr || head->next == nullptr || k == 0)
                return head;

            ListNode* start = head;
            int length = 1;
            while(start->next){
                length++;
                start = start->next;
            }
            k = k % length;
            if(k == 0) return head;
            start->next = head;

            while((--length)-k){
                head = head->next;
            }
            ListNode* next = head->next;
            head->next = nullptr;

            return next;            
        }
};