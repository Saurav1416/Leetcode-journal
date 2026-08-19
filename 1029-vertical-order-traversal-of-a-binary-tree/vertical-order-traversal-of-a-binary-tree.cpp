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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int,map<int,multiset<int>>> nodes;   //first int rep col  , second row and multiset cuz it can have multiple elt at same cell and we can get those at asc order
        // map used cuz so we can traverse key in asc order 
        queue<pair<TreeNode* , pair<int,int>>>queue;

        queue.push( {root,{0,0}});
        while(!queue.empty()){

            auto a = queue.front();
            auto p = a.second;
            queue.pop();
            TreeNode * x = a.first;
            nodes[p.second][p.first].insert(x->val);

            if( x->left){
                queue.push( {x->left,{p.first+1,p.second-1}});
            }
            if( x->right){
                queue.push( {x->right,{p.first+1,p.second+1}});
            }
        }

        vector<vector<int>> ans;

        for ( auto p :nodes){
            vector<int > col;
            for ( auto  q : p.second){
                col.insert(col.end(), q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};