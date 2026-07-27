class Solution {
public:
    void dfs ( unordered_map<int ,bool>&visited, int i, vector<vector<int>>& isConnected){
        visited[i]= true;

        for( int j = 0 ;j<isConnected.size();j++){
            if( isConnected[i][j] && !visited[j]){
                dfs( visited,j,isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        int m = isConnected[0].size();

      
        int count=0;
    

        
        unordered_map<int,bool>visited;

        for( int i =0; i<isConnected.size();i++){
            if( !visited[i]){
                visited[i]= true;
                for( int j =0;j<isConnected.size();j++){
                if( isConnected[i][j] && !visited[j]){
                    dfs( visited,j,isConnected);
                }
                
            }
                count++;
            }
            
            
        }

return count;
        
        
    }
};