class Solution {
public:
    int solve( int x, int y ,vector<vector<int>>& obstacleGrid,int n, int m ,
    vector<vector<int>>&dp ){

            if( obstacleGrid[y][x]==1) return 0;
            if( x==m-1 && y ==n-1) return 1;
            

            if( dp[y][x]!=-1) return dp[y][x];

            int down =0;
            int right =0;

            if( y+1<n)
             down = solve( x,y+1,obstacleGrid,n,m,dp);

            if( x+1<m)
               right = solve( x+1,y,obstacleGrid,n,m,dp);

              return dp[y][x]=down+right;




    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>>dp (n,vector<int>(m,-1));

       return  solve(0,0,obstacleGrid,n,m ,dp);
        
    }
};