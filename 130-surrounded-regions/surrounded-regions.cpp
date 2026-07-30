class Solution {
public:

     void dfs(vector<vector<char>>& grid,int y ,int x, vector<vector<int>>& visited){
        
        visited[y][x]= 1;
        
        
        vector< pair<int,int> > map = { {1,0},{0,1},{-1,0},{0,-1}};
        
        for ( auto i :map){
            
            int a = y+ i.first;
            int b = x + i.second;
            
            if(  a>=0 && a<grid.size()  && b>=0 && b<grid[0].size() && !visited[a][b] && grid[a][b]=='O'){
                dfs( grid,a,b,visited);
            }
        }
        
        
    }

    void solve(vector<vector<char>>& grid) {

          int n = grid.size();
        int m = grid[0].size();
        
         vector<vector<int>> visited ( n,  vector<int> ( m,0) );
         
        for( int j = 0;j<m;j++){
            
            if( !visited[0][j]  && grid[0][j]=='O'){
                
                dfs( grid,0,j,visited);
            }
        }
         for( int j = 0;j<m;j++){
            
            if( !visited[n-1][j] && grid[n-1][j]=='O'){
                
                dfs( grid,n-1,j,visited);
            }
        }
        
        for ( int i =0; i<n;i++ ){
            
            if( !visited[i][0] && grid[i][0]=='O'){
                
                dfs( grid, i,0,visited);
            }
        }
        
        for ( int i =0; i<n;i++ ){
            
            if( !visited[i][m-1] && grid [i][m-1]=='O'){
                
                dfs( grid, i,m-1,visited);
            }
        }
        
        
        for ( int i =0;i<n;i++){
            for ( int j =0 ;j<m ;j++){
                
                if (! visited[i][j] && grid[i][j]=='O' ){
                     grid[i][j]='X';
                    
                }
            }
        }
        
        
    }
};