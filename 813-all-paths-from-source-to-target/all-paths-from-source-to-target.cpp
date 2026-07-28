class Solution {
public:
    void dfs( vector<vector<int>> &anss,vector<int>ans,
    vector<vector<int>>& graph,int node,int tgt ){
        ans.push_back(node);
        if( node == tgt) {
            
            anss.push_back(ans);
            
           
        }
       
        

       else {for( auto i : graph[node]){
            
                dfs(anss,ans,graph,i,tgt);
            
        }}
        
        ans.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

     vector<vector<int>> anss;
     
     vector<int>ans;
     dfs(anss, ans ,graph,0,graph.size()-1);
     return anss;
        
    }
};