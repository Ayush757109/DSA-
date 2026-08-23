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
     int getheight(TreeNode* root){
        if(!root) return 0;
     int leftheight = getheight(root->left)+1;
     int rightheight = getheight(root->right)+1;
     int ans = max(leftheight , rightheight);
     return ans;
}
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int leftheight  = getheight(root->left);
        int rightheight = getheight(root->right);
        int absDiff = abs(leftheight - rightheight);
        if(absDiff >1){
            return false;
        }
        else{
           bool leftAns = isBalanced(root->left);
           bool rightAns = isBalanced(root->right);
           if(leftAns ==true && rightAns ==true){
            return true;
           } 
           else{
            return false;
           } 
        }
    }
};