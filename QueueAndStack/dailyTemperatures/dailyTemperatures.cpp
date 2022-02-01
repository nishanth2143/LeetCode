#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution{
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures){
            vector<int> results (temperatures.size());
            stack<pair<int, int>> data;
            for(int i = temperatures.size()-1; i>=0; i--){
                while(!data.empty()){
                    pair<int, int> tempAndIndex = data.top();
                    if(tempAndIndex.first > temperatures[i]){
                        results[i] = tempAndIndex.second - i;
                        break;
                    }
                    data.pop();
                }
                if(data.empty()){
                    results[i] = 0;
                }
                
                data.push({temperatures[i], i});
            }

            return results;
        }
};

int main(){
    vector<int> temperatures {73, 74, 75,71, 69, 72, 76, 73};

    Solution* soln = new Solution();
    vector<int> results = soln->dailyTemperatures(temperatures);
    for(int i = 0; i< results.size(); i++){
        cout<<results[i]<<endl;
    }

    return 0;
}