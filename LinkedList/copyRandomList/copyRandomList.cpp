#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution{
    private:
        void copyRandomPointers(Node* head){
            Node* start = head;
            /* assuming that no of elements is greater than 0 in original list. 
            So there will be atleast 1 + 1(duplicate) elements inside head */
            while(start){
                if(start->random)
                    start->next->random = start->random->next;
                start = start->next->next;
            }
        }

        Node* rearrangeLinks(Node* head){
            Node* nHead = head->next;
            Node* start = head;
            Node* next = nullptr;
            while(start && start->next){
                next = start->next;
                start->next = start->next->next;
                start = next;
            }

            return nHead;
        }

    public:
        Node* copyRandomList(Node* head){
            if(head == nullptr)
                return nullptr;

            Node* start = head;
            Node* newHead = nullptr;
            Node* next = nullptr;
            while(start){
                next = start->next;
                Node* newNode = new Node(start->val);
                start->next = newNode;
                newNode->next = next;
                start = next;
            }

            copyRandomPointers(head);

            return rearrangeLinks(head);
        }
};