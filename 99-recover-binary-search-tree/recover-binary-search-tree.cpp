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
    void inorder(TreeNode * root, vector<int> & ans){
        if( !root) return ;

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode *  correct( TreeNode * root, int a, int b){

        if( !root) return nullptr;

        if( root->val ==a){
           return root;
        }
       TreeNode * x = correct( root->left,a,b);
       if( x) return x;
        TreeNode * y = correct(root->right,a,b);
        if( y ) return y;
        return nullptr;

    }
    void recoverTree(TreeNode* root) {

        vector<int>ans;

        inorder( root,ans);
        int a = INT_MIN;
        int b =INT_MIN;

        for( int i =0 ;i<ans.size()-1;i++){
            if( a!=INT_MIN && ans[i]>ans[i+1] ){
                b= ans[i+1];
            }
            else if( ans[i]>ans[i+1]){
                a= ans[i];
                b = ans[i+1];
            }

        }
        TreeNode * x=correct( root, a,b);
        TreeNode * y = correct(root,b,a);
        int temp = x->val;
        x->val = y->val;
        y->val = temp;
        return;
        
    }
};