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
        return maxg;
    }

private:
    int maxg = -1*pow(2, 31) + 1;
    
    int dfs(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int maxl = dfs(root -> left);
        int maxr = dfs(root -> right);
        maxl = max(maxl, 0);
        // maxl = maxl >= 0 ? maxl : 0;
        maxr = max(maxr, 0);
        int valr = max(root -> val, 0);
        
        int res = max(maxl, maxr) + root -> val;
        
        maxg = max(maxg, maxl + maxr + valr);
        
        return res;
        
    }
};