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

    ListNode* reverseList(ListNode *head){
        if(!head || !head->next) return head;

        ListNode *prev = nullptr, *current = head, *next = nullptr;

        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;

    }

    ListNode* midOfLL(ListNode* head){
        if(!head || !head->next) return head;

        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    public:
        bool isPalindrome(ListNode *head){
            /*  Find the mid of the LL. 
                Keep mid->next as head of second list.
                Reverse second list.
                Traverse first and reversed second list one by one.
                Check for palindrome.
                Reverse the reversed second list to get the original second list.
                Connect mid->next to second list.
            */
            if(!head && !head->next) return true;

            ListNode *mid = this->midOfLL(head);
            ListNode *newHead = mid->next;
            newHead = this->reverseList(newHead);
            ListNode *firstList = head;
            ListNode *secondList = newHead;
            bool isPalindrome = true;
            while(firstList && secondList){
                if(firstList->val != secondList->val){
                    isPalindrome = false;
                }

                firstList = firstList->next; secondList = secondList->next;
            }

            newHead = this->reverseList(newHead);
            mid->next = newHead;

            return isPalindrome;
        }
};