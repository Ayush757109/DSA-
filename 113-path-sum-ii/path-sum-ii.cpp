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
void solve(TreeNode* root , int sum , vector<vector<int>>& ans , vector<int>temp,int targetSum  ){
    if(!root) {
        return ;
    }
     sum = sum +root->val;
    temp.push_back(root->val);
    if(!root->left && !root->right){
        if(sum == targetSum){
            ans.push_back(temp);
             return ;
        }
    }
    solve(root->left  , sum ,ans , temp, targetSum );
    solve(root->right , sum ,ans , temp,targetSum);

}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<vector<int>> ans;
        vector<int>temp;
        solve(root ,sum ,ans , temp,targetSum );
        return ans;
    }
};