#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution{

    private:
        Node* lastNodeInChild(Node* childNode){
            Node* start = childNode;
            Node* childLastNode = nullptr;
            Node* lastNode = nullptr;
            while(start){
                if(start->child){
                    childLastNode = lastNodeInChild(start->child);
                    rearrangeLinks(start, childLastNode);
                    start = childLastNode;
                }
                if(start->next == nullptr)
                    lastNode = start;
                start = start->next;
            }

            return lastNode;
        }

        void rearrangeLinks(Node* node, Node* childLastNode){
            Node* next = node->next;
            node->next = node->child;
            node->child->prev = node;
            node->child = nullptr;
            childLastNode->next = next;
            if(next)
                next->prev = childLastNode;
        }

    public:
        Node* flatten(Node* head){
            lastNodeInChild(head);

            return head;
        }
};