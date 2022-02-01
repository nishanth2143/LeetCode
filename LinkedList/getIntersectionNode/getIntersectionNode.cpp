#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
            ListNode *A = headA, *B = headB;
            int lengthA = 0, lengthB = 0;
            while(A!=nullptr){
                lengthA++;
                A = A->next;
            }

            while(B!=nullptr){
                lengthB++;
                B = B->next;
            }

            A = headA, B = headB;
            if(lengthB > lengthA){
                A = headB; B = headA;
                lengthA = lengthA + lengthB;
                lengthB = lengthA - lengthB;
                lengthA = lengthA - lengthB;
            }
            int diff = lengthA - lengthB;
            while(diff > 0){
                A = A->next;
                diff--;
            }

            while(A != nullptr && B != nullptr){
                if(A == B)
                    return A;
                A = A->next;
                B = B->next;
            }

            return nullptr;
        }
};