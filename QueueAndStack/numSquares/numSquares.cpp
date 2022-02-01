#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int numSquares(int n){
            if(n <= 3)
                return n;
                        
            queue<int> queueData;
            unordered_set<int> visited;
            queueData.push(n);
            visited.insert(n);
            int step = 0;

            while(!queueData.empty()){
                int size = queueData.size();
                for(int i = 0; i < size; i++){
                    int val = queueData.front();
                    if(val == 0)
                        return step;
                    int j = 1;
                    while(j*j <= val){
                        int diff = val - j*j;
                        if(diff == 0)
                            return step + 1;
                        if(visited.find(diff) == visited.end()){
                            queueData.push(diff);
                            visited.insert(diff);
                        }
                        
                        j++;
                    }
                    queueData.pop();
                }
                step = step + 1;                
                
            }

            return n;
        }
};

int main(){
    Solution* soln = new Solution();
    int x = soln->numSquares(12);

    return 0;
}