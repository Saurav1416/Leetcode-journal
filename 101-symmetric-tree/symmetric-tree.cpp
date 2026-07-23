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
    bool isSymmetric(TreeNode* root) {
        
        return issym( root->left, root->right);
    }
    bool issym( TreeNode* a ,TreeNode *  b ){

        if( a==nullptr && b == nullptr){
            return true;
        }
        if( !a || !b){
            return false;
        }
        if( a->val != b->val){
            return false;
        }
        bool aa = issym( a->left, b->right);
        bool bb = issym ( a->right, b->left);
        return ( aa&&bb);
    }
};