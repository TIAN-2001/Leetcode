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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if(root == NULL)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 1;
        
        while(!q.empty()){
            int sz = q.size();
            vector<int> resCurLayer;
            for(int i = 0; i < sz; ++i){
                TreeNode* cur = q.front();
                resCurLayer.push_back(cur -> val);
                q.pop();

                if(cur -> left != NULL)
                    q.push(cur -> left);
                if(cur -> right != NULL)
                    q.push(cur -> right);                        
            }
            
            if(level % 2 == 0){
                reverse(resCurLayer.begin(), resCurLayer.end());
            }
            
            res.push_back(resCurLayer);
            ++level;           
            
        }
        
        return res;
        
    }
};