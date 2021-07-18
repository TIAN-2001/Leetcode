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

// go through some examples, like corner case. 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // base case
        if(root == NULL){
            return 0;
        }
        
        // bottom up; post order; believe your recursive function
        int maxDepthL = maxDepth(root -> left);
        int maxDepthR = maxDepth(root -> right);
        int res = max(maxDepthL, maxDepthR) + 1;
        
        return res;
    }
};