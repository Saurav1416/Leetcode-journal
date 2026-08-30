/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void solve( TreeNode * root,unordered_map<int,vector<int>>&adj ){

        if ( !root) return ;

        if( root->left){
            adj[root->val].push_back( root->left->val);
            adj[root->left->val].push_back( root->val);
            solve( root->left, adj);    
        }
        if( root->right){

            adj[root->val].push_back( root->right->val);
            adj[root->right->val].push_back( root->val);
            solve( root->right,adj);
        }

        return ;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        if ( k == 0) return {target->val};

        unordered_map<int,vector<int>>adj;


        solve ( root,adj);

        queue<int> q;

        q.push(target->val);
        int cnt =1;
        vector<int> ans;
        vector<bool> v( 501,false);
        v[target->val] = true;
        while( !q.empty() && cnt<=k){

            int s = q.size();

            for( int i =0;i<s;i++){
                int a = q.front();
               
                q.pop();
                for( auto j : adj[a]){
                    if( !v[j]){
                        v[j] = true;
                        q.push(j);
                        
                        if( cnt==k){
                            ans.push_back(j);
                        }
                    }
                }
            }
            
            cnt++;
            
        }

        return ans;

    

        
    }
};