#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    queue<int> Q1;

    public:
        /** Initialize your data structure here. */
        MyStack() {
        }
        
        /** Push element x onto stack. */
        void push(int x) {
            int size = Q1.size();
            Q1.push(x);            
            while(size-- > 0){
                int val = Q1.front();
                Q1.pop();
                Q1.push(val);
            }
        }
        
        /** Removes the element on top of the stack and returns that element. */
        int pop() {
            int val = Q1.front();
            Q1.pop();
            return val;
        }
        
        /** Get the top element. */
        int top() {
            return Q1.front();
        }
        
        /** Returns whether the stack is empty. */
        bool empty() {
            return Q1.empty();
        }
};