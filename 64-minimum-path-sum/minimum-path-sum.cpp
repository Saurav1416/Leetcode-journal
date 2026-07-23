class Solution {
public:
    int solve( int x,int y ,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if( x== grid[0].size()-1 && y == grid.size()-1) return grid[y][x];

        if( dp[y][x]!=-1) return dp[y][x];

        //down
        int a = INT_MAX;
        int b =INT_MAX;
        if( y+1<grid.size()){
            a= solve( x,y+1,grid,dp)+ grid[y][x];
        }
        //right
        if( x+1<grid[0].size()){
            b= solve(x+1,y,grid,dp) + grid[y][x];
        }
        return dp[y][x]=min(a,b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return sum(0,0, grid,dp);
    }








    int sum(int x ,int y , vector<vector<int>> &grid ,vector<vector<int>> &dp){

        if(  y == grid.size()-1 && x == grid[0].size()-1){

            return grid[y][x];

        }

        if( dp[y][x]!=-1) return dp[y][x];

        int t =0;
        int a =INT_MAX;
        int b =INT_MAX;
        if( x+1< grid[0].size()){
           a= sum (x+1,y,grid,dp);
        }
        if( y+1<grid.size()){
           b= sum( x,y+1,grid,dp);
        }
        t = min(a,b )+ grid[y][x];
        return  dp[y][x]=t;

    }
















};