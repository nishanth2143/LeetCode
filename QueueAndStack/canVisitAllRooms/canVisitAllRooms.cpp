#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{

    bool BFS(vector<vector<int>>& rooms, int rowCount){
        queue<int> queueData;
        vector<int> visited;
        int totalRooms = rowCount;
        queueData.push(0);
        visited.push_back(0);

        while(!queueData.empty()){
            int size = queueData.size();
            for(int i=0; i<size; i++){
                totalRooms--;
                if(totalRooms <=0)
                    return true;
                int index = queueData.front();
                for(int key : rooms[index]){
                    if(find(visited.begin(), visited.end(), key) == visited.end()){
                        queueData.push(key);
                        visited.push_back(key);
                    }
                }
                queueData.pop();
            }
        }

        return totalRooms <= 0;
    }

    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms){
            return BFS(rooms, rooms.size());
        }
};

int main(){
    Solution* soln = new Solution();
    vector<vector<int>> rooms {{1}, {2}, {3}, {}};
    cout<< soln->canVisitAllRooms(rooms);

    return 0;
}