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
 void Lview(TreeNode*root , vector<int>&ans, int level){
    if(!root) return;
    if(ans.size()==level){
        ans.push_back(root->val);
    }
    Lview(root->right , ans , level+1);
    Lview(root->left , ans , level+1);
 }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int level ;
        Lview(root , ans ,0);
        return ans;


        
    }
};