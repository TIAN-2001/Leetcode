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
    int sumNumbers(TreeNode* root) {
        if(root == NULL)    
            return 0;
        
        dfs(root, 0);
        return sumg;
    }
    
private:
    int sumg = 0;
    
    void dfs(TreeNode* root, int num){
        if(root == NULL)
            return;
        
        num = num*10 + root -> val;
        if(root -> left == NULL && root -> right == NULL){
            sumg += num;
            return;
        }
        
        dfs(root -> left, num);
        dfs(root -> right, num);
    }
};