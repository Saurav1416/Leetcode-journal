class Solution {
public:
    void solve( unordered_map<int,vector<int>> &adj,vector<int> &v,vector<int> &dfsv,int &ans,int n ){


        dfsv[n] = 1;
        for( auto i: adj[n]){
            if( v[i]==-1){
                
                v[i] = v[n]+1;
                solve( adj,v,dfsv,ans,i);
            }
            else if(dfsv[i]== 1 ){
                int y = v[n]-v[i]+1;
                ans = max(ans,y);
            }
        }
        dfsv[n]= -1;

    }
    int longestCycle(vector<int>& edges) {

        int n = edges.size();
        unordered_map<int,vector<int>>adj;

        for( int i =0;i<n;i++){

            if( edges[i]==-1) continue;

            adj[i].push_back(edges[i]);
        }
        vector<int> v( n,-1);
        
        vector<int>dfsv( n,-1);
        vector<int>parent;
        int ans= -1;
        for( int i =0;i<n;i++){
                if( v[i]==-1){
                    v[i]=1;
                    solve( adj,v,dfsv,ans,i);
                }
        }
        return ans;
        

      

        
    }
};