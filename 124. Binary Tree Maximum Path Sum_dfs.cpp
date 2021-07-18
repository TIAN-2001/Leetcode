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
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
    
private:
    int res = -1*pow(2,31) + 1;
    
    int dfs(TreeNode* root){
        //base case
        if(root == NULL){
            return 0;
        }
        
        // bottomup; post order
        int resLeft = dfs(root -> left);
        resLeft = resLeft < 0 ? 0 : resLeft;
        int resRight = dfs(root -> right);
        resRight = resRight < 0 ? 0 : resRight;
        res = max(res, resLeft + resRight + root->val);
        return max(resLeft + root->val, resRight + root->val);
    }
};