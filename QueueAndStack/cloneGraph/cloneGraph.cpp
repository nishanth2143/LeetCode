#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct Node
{
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors(vector<Node *>()) {}
    Node(int val) : val(val), neighbors(vector<Node *>()) {}
    Node(int val, vector<Node *> neighbors) : val(val), neighbors(neighbors) {}
};

class Solution
{
    void DFS(Node* clonedNode, Node* neighboringNode, vector<pair<Node*, Node*>>& mapping, vector<Node*>& visited){
        Node* clonedNeighboringNode = new Node(neighboringNode->val);
        visited.push_back(neighboringNode);
        mapping.push_back({neighboringNode, clonedNeighboringNode});
        clonedNode->neighbors.push_back(clonedNeighboringNode);
        for(Node* neighbor : neighboringNode->neighbors){
            // if neighbor already exists in visited list, then find its mapping and link to that node.
            if(find(visited.begin(), visited.end(), neighbor) != visited.end()){
                auto pos = std::find_if(mapping.begin(), mapping.end(),
                        [neighbor](std::pair<Node*, Node*> const &b) { 
                            return b.first == neighbor; 
                        });
                
                clonedNeighboringNode->neighbors.push_back((*pos).second);
            }
            else{
                DFS(clonedNeighboringNode, neighbor, mapping, visited);
            }
        }
    }

    public:
        Node* cloneGraph(Node* node){
            if(node == nullptr || node->neighbors.empty()){
                return node ? new Node(node->val) : nullptr;
            }

            vector<pair<Node*, Node*>> mapping;
            Node* start = node;
            Node* clonedStart = new Node(start->val);
            vector<Node*> visited;
            visited.push_back(start);
            mapping.push_back({start, clonedStart});
            for(Node* neighbor : start->neighbors){
                // if neighbor doesnt exist in visited list, call DFS to process that node.
                if(find(visited.begin(), visited.end(), neighbor) == visited.end()){
                    DFS(clonedStart, neighbor, mapping, visited);
                }else{
                    auto pos = std::find_if(mapping.begin(), mapping.end(),
                        [neighbor](std::pair<Node*, Node*> const &b) { 
                            return b.first == neighbor; 
                        });
                    clonedStart->neighbors.push_back((*pos).second);
                }
            }

            return clonedStart;
        }
};

int main(){
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    one->neighbors.push_back(two); one->neighbors.push_back(four);
    two->neighbors.push_back(one); two->neighbors.push_back(three); 
    three->neighbors.push_back(two); three->neighbors.push_back(four);
    four->neighbors.push_back(one); four->neighbors.push_back(three);

    Solution* soln = new Solution();
    Node* newHead = soln->cloneGraph(one);

    return 0;
}