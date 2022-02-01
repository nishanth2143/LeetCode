#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    public:
        ListNode *reverseList(ListNode *head){
            ListNode *start = head;
            while(start != nullptr){
                ListNode *temp = new ListNode(start->val, head == start ? nullptr : head);
                head = temp;

                start = start->next;
            }

            return head;
        }

        ListNode *reverListImproved(ListNode *head){
            ListNode *prev = nullptr;

            while(head){
                ListNode *next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }

            return prev;
        }
};