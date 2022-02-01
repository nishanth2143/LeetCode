#include <iostream>
#include <bits/stdc++.h>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution{
    public:
        vector<int> inorderTraversal(TreeNode* root){
            stack<TreeNode*> sData;
            vector<TreeNode*> visited;
            vector<int> values;
            if(root == nullptr)
                return values;
            sData.push(root);
            visited.push_back(root);

            while(!sData.empty()){
                TreeNode* node = sData.top();
                // left node exists and if not visited yet, push into visited and stack.
                if(node->left && find(visited.begin(), visited.end(), node->left) == visited.end()){
                    visited.push_back(node->left);
                    sData.push(node->left);
                }
                else {
                    values.push_back(node->val);
                    sData.pop();
                    if(node->right){
                        visited.push_back(node->right);
                        sData.push(node->right);
                    }
                }
            }

            return values;
        }
};

int main(){

}