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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int ans;
        int count =0;
        while(curr){
            if(!curr->left){
                count++;
                if(count==k) ans = curr->val;
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(!prev->right){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = nullptr;
                    count++;
                    if(count==k) ans = curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
