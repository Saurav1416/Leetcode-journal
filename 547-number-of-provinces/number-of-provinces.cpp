class Solution {
public:
    void dfs ( unordered_map<int ,bool>&visited, int i, unordered_map<int, vector<int> >&um){
        visited[i]= true;

        for( auto j: um[i]){
            if( !visited[j]){
                dfs( visited,j,um);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        int m = isConnected[0].size();

      
        int count=0;
        unordered_map<int, vector<int> >um;

        for( int i =0 ;i< n;i++){
            for( int j =0;j<m;j++){
                 if ( isConnected[i][j] ){
                    um[i].push_back(j);
                 }
            }
        }
        unordered_map<int,bool>visited;

        for( auto i :um){
            
            if( !visited[i.first]){
                dfs(visited,i.first,um );
                count++;
            }
        }

return count;
        
        
    }
};