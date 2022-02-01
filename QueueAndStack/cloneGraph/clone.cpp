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
    Node* DFS(Node* node, map<int, Node*>& map){
        if(map.find(node->val) != map.end()) return (*map.find(node->val)).second;
        Node* copy = new Node(node->val);
        map.insert({node->val, copy});
        for(Node* neighbor : node->neighbors) copy->neighbors.push_back(DFS(neighbor, map));

        return copy;        
    }

    public:
        Node* cloneGraph(Node* node){
            if(node == nullptr || node->neighbors.empty()){
                return node ? new Node(node->val) : nullptr;
            }
            map<int, Node*> map;

            return DFS(node, map);
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