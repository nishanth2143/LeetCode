#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class MyQueue {
    stack<int> S1;
    stack<int> S2;

    bool copyFromS1ToS2(){
        if(S1.empty())
            return false;

        while(!S1.empty()){
            S2.push(S1.top());
            S1.pop();            
        }
        return true;
    }

    public:
        /** Initialize your data structure here. */
        MyQueue() {
            
        }
        
        /** Push element x to the back of queue. */
        void push(int x) {
            S1.push(x);
        }
        
        /** Removes the element from in front of queue and returns that element. */
        int pop() {
            if(S2.empty()){
                if(!copyFromS1ToS2())
                    return -1;
            }
            int val = S2.top();
            S2.pop();

            return val;
        }
        
        /** Get the front element. */
        int peek() {
            if(S2.empty()){
                if(!copyFromS1ToS2())
                    return -1;
            }
            return S2.top();
        }
        
        /** Returns whether the queue is empty. */
        bool empty() {
            return S1.empty() && S2.empty();
        }
};
