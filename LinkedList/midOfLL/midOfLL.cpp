#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int val): val(val), next(nullptr){}
    ListNode(int val, ListNode *next): val(val), next(next){}
};

class Solution{
    public:
        int midOfLL(ListNode *head){
            if(!head || !head->next) return head ? head->val : -1;
            
            ListNode *slow = head;
            ListNode *fast = head;            

            while(fast->next && fast->next->next){
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow->val;
        }

};

int main(){
    ListNode *head = new ListNode(0);
    ListNode *first = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *ten = new ListNode(10);
    ListNode *twenty = new ListNode(20);
    ListNode *thirty = new ListNode(30);
    head->next = first; first->next = second; second->next = third;  third->next = ten; ten->next = twenty; 
    // twenty->next = thirty;

    Solution *soln = new Solution();
    ListNode *start = head;
    while(start){
        cout<<start->val<<endl;
        start = start->next;
    }
    cout<<"The middle value is: "<<soln->midOfLL(head)<<endl;

    return 0;
}