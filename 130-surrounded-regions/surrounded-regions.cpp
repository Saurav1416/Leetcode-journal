class Solution {
public:

     void dfs(vector<vector<char>>& grid,int y ,int x,vector< pair<int,int> > &map ){
        
        grid[y][x]='#';
        
        
       
        for ( auto i :map){
            
            int a = y+ i.first;
            int b = x + i.second;
            
            if(  a>=0 && a<grid.size()  && b>=0 && b<grid[0].size()  && grid[a][b]=='O'){
                dfs( grid,a,b,map);
            }
        }
        
        
    }

    void solve(vector<vector<char>>& grid) {

          int n = grid.size();
        int m = grid[0].size();
        
         
          vector< pair<int,int> > map = { {1,0},{0,1},{-1,0},{0,-1}};
        
        for( int j = 0;j<m;j++){
            
            if(  grid[0][j]=='O'){
                
                dfs( grid,0,j,map);
            }

             if(  grid[n-1][j]=='O'){
                
                dfs( grid,n-1,j,map);
            }
        }
       
        
        for ( int i =0; i<n;i++ ){
            
            if(  grid[i][0]=='O'){
                
                dfs( grid, i,0,map);
            }

            if(grid [i][m-1]=='O'){
                
                dfs( grid, i,m-1,map);
            }
        }
        
       
        
        
        for ( int i =0;i<n;i++){
            for ( int j =0 ;j<m ;j++){
                
                if ( grid[i][j]=='O' ){
                     grid[i][j]='X';
                    
                }
                else if( grid[i][j]=='#' ){
                    grid[i][j]='O';
                }

            }
        }
        
        
    }
};