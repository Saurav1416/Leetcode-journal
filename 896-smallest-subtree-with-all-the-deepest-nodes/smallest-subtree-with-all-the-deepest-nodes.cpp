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

    TreeNode * solve( TreeNode * root, int &d){
        if( !root) {

            d = 0;
            return nullptr;
        }

        TreeNode * a = solve( root->left, d);

        int t =d;
        TreeNode * b = solve( root->right, d);
        if( t== d){
            d+=1;
            return root;
        }
        else if( t>d){
            d = t+1;
            return a;
        }
        else {
            d+=1;
            return b;
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
            int d =0;
        return solve( root, d);
    }
};