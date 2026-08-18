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
    int mp( TreeNode * root, int & maxx){
        if(! root) return 0;

        int a = mp( root->left,maxx);
        int b = mp (root->right,maxx);
        if( a<0) a =0;
        if( b <0) b =0;
        if( b >a) swap(b,a);

        if( root->val+a<=0 ) return 0;
        
        maxx = max( maxx, root->val+a+b);    //check if node is joining node 

        return root->val+a;   // to check furthur we do sum of root + max of left ,right . if we send sum of both then we assume that this node is joining node
    }
    bool ifallneg( TreeNode * root , int & minn){

        if( !root) return true;

        minn = max( minn, root->val);

        bool a = ifallneg(root->left, minn);
        bool b = ifallneg( root->right,minn);

        if( a && b ){
            return (root->val<=0);
        }
        return false;
    }
    int maxPathSum(TreeNode* root) {
        int minn =INT_MIN;
        bool a = ifallneg(root,minn );
        if ( a ){
            return minn;
        }

        int maxx =INT_MIN;

        mp( root,maxx);
        return maxx;
        
    }
};