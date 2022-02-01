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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
            if(l1 == nullptr || l2 == nullptr)
                return l1 ? l1 : l2;

            ListNode* startl1 = l1; ListNode* startl2 = l2;
            ListNode* prev = nullptr;
            ListNode* head = l1;

            if(startl1->val > startl2->val){
                startl1 = startl2;
                startl2 = l1;
                head = l2;
            }

            while(startl1 && startl2){
                if(startl1->val <= startl2->val){
                    if(prev){
                        prev->next = startl1;
                        prev = prev->next;
                    }
                    else 
                        prev = startl1;
                    startl1 = startl1->next;
                }
                else {
                    prev->next = startl2;
                    startl2 = startl2->next;
                    prev = prev->next;
                }
            }

            while(startl1){
                prev->next = startl1;
                prev = prev->next;
                startl1 = startl1->next;
            }
            while(startl2){
                prev->next = startl2;
                prev = prev->next;
                startl2 = startl2->next;
            }

            return head;
        }
};

int main(){
    ListNode *l1 = new ListNode(1);
    ListNode *l1two = new ListNode(2);
    ListNode *l1three = new ListNode(3);
    ListNode *l2 = new ListNode(2);
    ListNode *l2two = new ListNode(4);
    ListNode *l2three = new ListNode(6);
    l1->next = l1two; l1two->next = l1three;
    l2->next = l2two; l2two->next = l2three;

    Solution *soln = new Solution();
    ListNode *start = soln->mergeTwoLists(l1, l2);
    while(start){
        cout<<start->val<<endl;
        start = start->next;
    }
    // cout<<"The middle value is: "<<soln->midOfLL(head)<<endl;

    return 0;
}