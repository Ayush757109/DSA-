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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
           int level = q.size();
           int ans = INT_MIN;
        while(level--){
           TreeNode* temp = q.front();
            q.pop();
                   ans = max(ans, temp->val);
          if(temp->left){
          q.push(temp->left);
          }
          if(temp->right){
          q.push(temp->right);
          }
        }
          result.push_back(ans);
        }
        return result;
        
    }
    
};