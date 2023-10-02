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
    map<pair<TreeNode*,int>, int> dp;
    int solve(TreeNode* root,int pick){
        if(root == NULL) return 0;

        if(dp.find({root,pick}) != dp.end()) return dp[{root,pick}];

        int ex = 0, inc = 0;
        if(pick == 0){
            inc = root->val + solve(root->left,1) + solve(root->right,1);
            ex = solve(root->left,0) + solve(root->right,0);
        }
        else{
            ex = solve(root->left,0) + solve(root->right,0);
        }
      
        return dp[{root,pick}] = max(ex,inc);
    }
    int rob(TreeNode* root) {
        return solve(root,0);
    }
};
