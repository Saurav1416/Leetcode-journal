class Solution {
public:
    vector<int> dx ={1,0,-1,0};
    vector<int>dy = {0,1,0,-1};

    void dfs( vector<vector<int>>& grid,int y , int x ,int n , int m){

        
        grid[y][x]=2;

        for( int i =0;i<4;i++){

            int nx = dx[i]+x;
            int ny = dy[i]+y;
            if( nx<m && nx>=0 && ny <n && ny>=0 && grid[ny][nx]==1){
                dfs( grid, ny,nx,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

       
        int ans =0;
        for( int i =0;i<n;i++){

            if( grid[i][0]==1 )  dfs(grid,i,0,n,m);
           
            if( grid[i][m-1]==1)
            dfs(grid,i,m-1,n,m);
        }

        for( int i =0;i<m;i++){

            if( grid[0][i]==1 ){
                dfs( grid, 0,i,n,m);
            }
            if( grid[n-1][i]==1){
                dfs(grid,n-1,i,n,m);
            }
        }

        for( int i =0;i<n;i++){
            for( int j=0;j<m;j++){
                if( grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;

        
    }
};