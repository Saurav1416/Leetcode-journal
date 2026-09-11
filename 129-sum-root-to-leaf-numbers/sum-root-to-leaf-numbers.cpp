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
    void solve( TreeNode * root, int & ans, int anss,int mul){

        if ( !root->left && !root->right){
            anss = mul* anss + root->val;
            ans+= anss;
            return ;
        }

        anss = mul * anss + root->val;
        if( root->left)
        solve( root->left, ans, anss, mul);
        if( root->right)
        solve( root->right,ans,anss, mul);
    }
    int sumNumbers(TreeNode* root) {
       
        int ans =0;

        solve( root, ans, 0,10);
        return ans;
    }
};