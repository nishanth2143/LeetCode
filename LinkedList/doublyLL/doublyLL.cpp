#include <iostream>

using namespace std;

// Definition for doubly-linked list.
struct DoublyListNode {
    int val;
    DoublyListNode *prev;
    DoublyListNode *next;
    DoublyListNode(): val(0), next(nullptr), prev(nullptr) {}
    DoublyListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    DoublyListNode(int x, DoublyListNode *prev, DoublyListNode *next): val(x), prev(prev), next(next) {}
};

class MyLinkedList {
    
private:
    DoublyListNode* head;
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
        DoublyListNode* current = head;
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
        DoublyListNode* newNode = new DoublyListNode(val, nullptr, head);
        if(head)
            head->prev = newNode;
        this->head = newNode;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(this->head == nullptr){
            this->addAtHead(val);
            return;
        }
        DoublyListNode* newNode = new DoublyListNode(val, nullptr, nullptr);
        DoublyListNode* start = this->head;
        while(start->next != nullptr){
            start = start->next;
        }
        start->next = newNode;
        newNode->prev = start;
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
            DoublyListNode* current = this->head;
            int i = 0;
            while(current != nullptr){
                if(i == index){
                    DoublyListNode* newNode = new DoublyListNode(val, current->prev, current); 
                    current->prev->next = newNode;
                    current->prev = newNode;
                    size++;
                    break;
                }
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
            if(head)
                head->prev = nullptr;
            size--;
            return;
        }
        DoublyListNode* current = this->head;
        int i = 0;
        while(current != nullptr){
            if(i == index){
                current->prev->next = current->next;
                if(current->next)
                    current->next->prev = current->prev;
                size--;
                break;
            }
            current = current->next;
            i++;
        }

        return;
    }

    void printAll(){
        DoublyListNode* start = head;
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
    // obj->printAll();
    obj->deleteAtIndex(1); 

    obj->addAtHead(2);
    obj->addAtHead(7);
    obj->addAtHead(3);
    obj->addAtHead(2);
    obj->addAtHead(5);

    obj->addAtTail(5);
    obj->get(5);
    obj->deleteAtIndex(6);
    obj->deleteAtIndex(4);
    obj->printAll();
    // obj->addAtIndex(1,2);
    // obj->printAll();
    // obj->deleteAtIndex(0); 
    // obj->printAll();

    return 0;
}