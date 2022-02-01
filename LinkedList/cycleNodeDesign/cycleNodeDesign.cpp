#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
    public:
        void cycleNodeDesign(ListNode *head){
            /* when there is empty list or head not pointing to any node, there is no cycle. */
            if(head == nullptr || head->next == nullptr) return;

            ListNode *slow = head, *fast = head, *refNode;

            while(fast != nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;

                if(fast == slow){
                    refNode = fast;
                    break;
                }
            }    

            /*NO CYCLE*/
            if(fast != slow)
                return;  

            /* 
            CYCLE EXISTS
                Properties to find:
                Length of tail, starting node of cycle, length of cycle 
            */

            cout<<"I have discovered a cycle."<<endl;
            int tailLength = 0, cycleLength = 0;
            ListNode *cycleStartingNode = nullptr;
            slow = head;
            tailLength++;
            while(slow != fast){
                slow = slow->next;
                tailLength++;
                fast = fast->next;
                cycleLength++;                
            }
            cycleStartingNode = slow;

            while(fast!=refNode){
                fast = fast->next;
                cycleLength++;                
            }

            cout<<"Length of tail: "<<tailLength<<endl;
            cout<<"Length of cycle: "<<cycleLength<<endl;
            cout<<"Total nodes in the list: "<<(tailLength + cycleLength - 1)<<endl;
            cout<<"Cycle starts at node value: "<<cycleStartingNode->val<<endl;            

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
    twenty->next = thirty; thirty->next = second;

    Solution *soln = new Solution();
    soln->cycleNodeDesign(head);

    return 0;
}