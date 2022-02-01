#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
    
private:
    SinglyListNode* head;
    int size;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0)
            return -1;

        int i = 0;
        SinglyListNode* current = head;
        while(current != nullptr){
            if(i == index)
                return current->val;
            
            current = current->next;
            i++;
        }

        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        SinglyListNode* newNode = new SinglyListNode(val);
        newNode->next = this->head;
        this->head = newNode;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        SinglyListNode* newNode = new SinglyListNode(val);
        if(this->head == nullptr){
            this->addAtHead(val);
            return;
        }
        SinglyListNode* start = this->head;
        while(start->next != nullptr){
            start = start->next;
        }
        start->next = newNode;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size)
            return;
        else if(index == 0)
            this->addAtHead(val);
        else if(index == size)
            this->addAtTail(val);
        else {
            SinglyListNode* current = this->head;
            SinglyListNode* prev = nullptr;
            int i = 0;
            while(current != nullptr){
                if(i == index){
                    SinglyListNode* newNode = new SinglyListNode(val);
                    prev->next = newNode;
                    newNode->next = current;
                    size++;
                    break;
                }
                prev = current;
                current = current->next;
                i++;
            }
        }
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;
        if(index == 0){
            head = head->next;
            size--;
            return;
        }
        SinglyListNode* current = this->head;
        SinglyListNode* prev = nullptr;
        int i = 0;
        while(current != nullptr){
            if(i == index){
                prev->next = current->next;
                size--;
                break;
            }
            prev = current;
            current = current->next;
            i++;
        }

        return;
    }

    void printAll(){
        SinglyListNode* start = head;
        int i = 0;
        while(start != nullptr){
            cout<<(i+1)<<". "<<start->val<<endl;
            start = start->next;
            i++;
        }
        cout<<"\n";
    }
};

int main(){
    //  Your MyLinkedList object will be instantiated and called as such:
    MyLinkedList* obj = new MyLinkedList();
    int param_1 = obj->get(5);
    obj->printAll();
    obj->addAtHead(2);
    obj->printAll();
    obj->deleteAtIndex(1); 

    obj->addAtTail(3);
    obj->printAll();
    obj->addAtIndex(1,2);
    obj->printAll();
    obj->deleteAtIndex(0); 
    obj->printAll();

    return 0;
}