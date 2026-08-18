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
    void inorder(TreeNode* root,
             TreeNode*& prev,
             TreeNode*& curr,
             TreeNode*& a,
             TreeNode*& b){
        if( !root) return ;

        inorder( root->left,prev,curr, a,b);

        curr = root;
        if(a && curr->val< prev->val ){
            b= curr;
        }
        else if(curr->val<prev->val){
            a = prev;
            b = curr;
        }
        prev= root;
        inorder( root->right,prev,curr,a,b);
        
    }
    
    void recoverTree(TreeNode* root) {

        vector<int>ans;
        TreeNode * prev =new TreeNode(INT_MIN);
        TreeNode * curr =new TreeNode(INT_MIN);TreeNode *a = nullptr;
        TreeNode * b  ;
        


        inorder( root,prev,curr,a,b);
        int temp = a->val;
        a->val = b->val;
        b->val  =temp;
        

      
        
    }
};