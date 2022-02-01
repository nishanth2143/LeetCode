#include <iostream>
#include <vector>

using namespace std;

class MinStack {
    vector<int> data;

    public:
        /** initialize your data structure here. */
        MinStack() {
            
        }
        
        void push(int val) {
            data.push_back(val);
        }
        
        void pop() {
            data.pop_back();
        }
        
        int top() {
            return data.back();
        }
        
        int getMin() {
            int min = data[0];
            for(int i = 1; i< data.size(); i++){
                if(data[i] < min)
                    min = data[i];
            }

            return min;
        }
};