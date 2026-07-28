class Solution {
public:
    void dfs( vector<vector<int>> &anss,vector<int>ans, vector<bool>& visited,
    vector<vector<int>>& graph,int node,int tgt ){

        if( node == tgt) {
            ans.push_back(node);
            anss.push_back(ans);
            ans.pop_back();
            return ;
        }
        visited[node]= true;
        ans.push_back(node);

        for( auto i : graph[node]){
            if( !visited[i]){
                dfs(anss,ans,visited,graph,i,tgt);
            }
        }
        visited[node]= false;
        ans.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

     vector<vector<int>> anss;
     vector<bool>visited( graph.size(),false);
     vector<int>ans;
     dfs(anss, ans ,visited,graph,0,graph.size()-1);
     return anss;
        
    }
};