#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    vector<Node*> neighbors;
    Node* next;
    Node() : val(0), neighbors(vector<Node*>()) {}
    Node(int val) : val(val), neighbors(vector<Node*>()) {}
    Node(int val, vector<Node*> neighbors) : val(val), neighbors(neighbors) {}
};

class Solution
{
    bool DFS(Node *cur, Node *target, unordered_set<Node *> visited)
    {
        if (cur == target)
            return true;

        Node *start = cur->next;
        while (start)
        {
            if (find(visited.begin(), visited.end(), start) == visited.end())
            {
                visited.insert(start);
                bool isFound = DFS(start, target, visited);
                if (isFound)
                    return true;
            }
        }

        return false;
    }

    public:
        bool depthFirstSearch(Node *root, Node *target)
        {
            Node *start = root;
            unordered_set<Node *> visited;

            return DFS(start, target, visited);
        }

        bool depthFirstSearchUsingExplicitStack(Node *root, Node *target){
            vector<Node*> visited;
            stack<Node*> stackData;
            stackData.push(root);
            visited.push_back(root);

            while(!stackData.empty()){
                Node *lastInsertedNode = stackData.top();
                stackData.pop();
                if(lastInsertedNode == target)
                    return true;
                for(Node* neighbour : lastInsertedNode->neighbors){
                    // if neighbour not in visited, then insert into visited and push into stack.
                    if(find(visited.begin(), visited.end(), neighbour) == visited.end()){
                        visited.push_back(neighbour);
                        stackData.push(neighbour);
                    }
                }
            }
        }
};