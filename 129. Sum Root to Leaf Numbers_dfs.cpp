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
        dfs(root, 0);
        return sum;
    }
    
private:
    int sum = 0;
    
    // top down会有参数传下去，比如这个preSum
    void dfs(TreeNode* root, int preSum){
        // base case
        if(root == NULL){
            return;
        }
            
        if(root -> left == NULL && root -> right == NULL){
            sum += (preSum * 10 + root -> val);
            return;
        }
        
        // Top down; preorder
        int curSum = preSum * 10 + root -> val;
        
        dfs(root -> left, curSum);
        dfs(root -> right, curSum);

    }
};