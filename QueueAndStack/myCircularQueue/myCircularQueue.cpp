#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue{

    vector<int> data;
    int head, tail;

    void reset(int value){
        head = value;
        tail = value;
    }

    public:
        MyCircularQueue(int k) {
            data.resize(k);
            reset(-1);
        }

        bool enQueue(int value) {
            if(isFull())
                return false;
            
            if(isEmpty()){
                head = 0;
            }
            else{
                tail = (tail + 1) % data.size();
            }
            
            data[tail] = value;
            return true;
        }

        bool deQueue() {
            if(isEmpty())
                return false;
            
            if(head == tail){
                reset(-1);
            } else {
                head = (head + 1) % data.size();
            }

            return true;
        }

        int Front() {
            if(isEmpty())
                return -1;
            return data[head];
        }

        int Rear() {
            if(isEmpty())
                return -1;
            return data[tail];
        }

        bool isEmpty() {
            if(head < 0 && tail < 0)
                return true;
            return false;
        }

        bool isFull() {
            return ((tail + 1) % data.size()) == head;
        }        
};