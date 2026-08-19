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
    int i =0;
    int getValue(string traversal, int &i) {
    int num = 0;

    while (i < traversal.size() && traversal[i] != '-') {
        num = num * 10 + (traversal[i] - '0');
        i++;
    }

    return num;
}
    
    TreeNode * solve( string &traversal, int d , int t){

        if( t>=traversal.size()){
            return nullptr;
        }
        i =t;
        TreeNode * a  = new TreeNode ( getValue(traversal,i));
        
        for( int j=i;j<i+d;j++){

            if( j >= traversal.size() || traversal[j]!='-'){
               
                a->left = nullptr;
                a->right = nullptr;
                return a;
            }
        }
        a->left = solve(traversal,d+1,i+d);
        for( int j=i;j<i+d;j++){

            if( j >= traversal.size() || traversal[j]!='-'){
               
               
                a->right = nullptr;
                return a;
            }
        }
        a->right = solve( traversal,d+1,i+d);
        return a;


    }
    TreeNode* recoverFromPreorder(string traversal) {

        return solve( traversal, 1,0);
        
    }
};