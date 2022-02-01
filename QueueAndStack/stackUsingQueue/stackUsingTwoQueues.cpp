#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    queue<int> Q1;
    queue<int> Q2;

    void copyFromQ2ToQ1(){
        while(!Q2.empty()){
            Q1.push(Q2.front());
            Q2.pop();
        }
    }

    void copyFromQ1ToQ2(){
        while(!Q1.empty()){
            Q2.push(Q1.front());
            Q1.pop();
        }
    }

    public:
        /** Initialize your data structure here. */
        MyStack() {
        }
        
        /** Push element x onto stack. */
        void push(int x) {
            if(Q1.empty() && Q2.empty()){
                Q1.push(x);
            } else if(Q1.empty()){
                Q1.push(x);
                copyFromQ2ToQ1();
            } else{
                Q2.push(x);
                copyFromQ1ToQ2();
            }
        }
        
        /** Removes the element on top of the stack and returns that element. */
        int pop() {
            if(Q1.empty()){
                int val = Q2.front();
                Q2.pop();
                return val;
            }
            int val = Q1.front();
            Q1.pop();
            return val;
        }
        
        /** Get the top element. */
        int top() {
            if(Q1.empty())
                return Q2.front();
            return Q1.front();
        }
        
        /** Returns whether the stack is empty. */
        bool empty() {
            return Q1.empty() && Q2.empty();
        }
};