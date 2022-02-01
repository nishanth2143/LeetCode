#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr) {}
    ListNode(int val, ListNode* next): val(val), next(next) {}
};

class Solution{
    private:
        ListNode* reverse(ListNode* head){
            if(head == nullptr || head->next == nullptr)
                return head;

            ListNode* start = head;
            ListNode* prev = nullptr;
            ListNode* next = nullptr;
            while(start){
                next = start->next;
                start->next = prev;
                prev = start;
                start = next;
            }

            return prev;
        }

    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
            ListNode* s1 = l1;
            ListNode* s2 = l2;
            ListNode* s3 = nullptr;
            ListNode* head = nullptr;
            int carry_over = 0, sum = 0;
            while(s1 || s2){
                sum = (s1 ? s1->val : 0) + (s2 ? s2->val : 0) + carry_over;
                carry_over = sum/10;
                sum = sum % 10;
                ListNode* newNode = new ListNode(sum, nullptr);
                if(s3){
                    s3->next = newNode;
                    s3 = s3->next;
                }                    
                else{
                    s3 = newNode;
                    head = s3;
                }
                if(s1)
                    s1 = s1->next;
                if(s2)
                    s2 = s2->next;
                    
            }

            if(carry_over > 0){
                ListNode* newNode = new ListNode(carry_over, nullptr);
                s3->next = newNode;
            }

            return head;
        }
};