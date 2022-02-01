#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr) {}
    ListNode(int val, ListNode *next): val(val), next(next) {}
};

class Solution{
    public:
        ListNode *oddEvenList(ListNode *head){
            ListNode *start = head;
            ListNode *oddList = nullptr;
            ListNode *evenList = nullptr;
            ListNode *evenNodeStart = nullptr;
            int i=1;

            while(start){
                if(i++ % 2 == 0){
                    if(evenList == nullptr)
                        evenNodeStart = start;
                    else
                        evenList->next = start;
                    evenList = start;
                }
                else{
                    if(oddList)
                        oddList->next = start;
                    oddList = start;
                }

                start = start->next;
                
            }
            if(evenList)
                evenList->next = nullptr;
            if(oddList)
                oddList->next = evenNodeStart;

            return head;
        }
};

int main(){
    ListNode *head = new ListNode(1);
    ListNode *first = new ListNode(2);
    ListNode *second = new ListNode(3);
    ListNode *third = new ListNode(4);
    ListNode *fourth = new ListNode(5, nullptr);
    head->next = first; first->next = second; second->next = third; third->next = fourth;

    Solution *soln = new Solution();
    head = soln->oddEvenList(head);

    while(head){
        cout<<head->val<<endl;
        head = head->next;
    }

    return 0;
}