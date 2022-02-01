#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr){}
    Node(int val): val(val), next(nullptr){}
    Node(int val, Node* next):val(val), next(next) {}
};

class Solution{
    public:
        int breadFirstSearch(Node* root, Node* target){
            queue<Node*> queueData;
            int step = 0;
            queueData.push(root);

            while(!queueData.empty()){
                int size = queueData.size();
                step = step + 1;
                for(int i = 0; i < size; i++){
                    Node* current = queueData.front();
                    if(current == target){
                        return step;
                    }
                    /* for Node next : neighbours of current */
                    while(current->next){
                        queueData.push(current->next);
                        current = current->next;
                    }
                    queueData.pop();
                }
            }

            return -1;
        }

        int breadthFirstSearchUsingHashSet(Node* root, Node* target){
            queue<Node*> queueData;
            int step = 0;
            unordered_set<Node*> visited;

            queueData.push(root);
            visited.insert(root);

            while(!queueData.empty()){
                step = step + 1;
                int size = queueData.size();

                for(int i = 0; i < size; i++){
                    Node* current = queueData.front();
                    if(current == target)
                        return step;
                    
                    /* for Node next : neighbours of current */
                    while(current->next){
                        /* if key is not found */
                        if(visited.find(current->next) == visited.end()){
                            visited.insert(current->next);
                            queueData.push(current->next);
                        }
                    }

                    queueData.pop();
                }
            }

            return -1;
        }
};