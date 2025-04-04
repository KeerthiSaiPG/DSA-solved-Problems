/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long width = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long long mini = q.front().second;
            long long first=0,last=0;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                long long currInd = q.front().second-mini;
                q.pop();
                if(i==0) first = currInd;
                if(i==size-1) last = currInd;
                if(node->left) q.push({node->left,currInd*2+1});
                if(node->right) q.push({node->right,currInd*2+2});
            }
            width = max(width,last-first+1);
        }
        return static_cast<int>(width);
    }
};
