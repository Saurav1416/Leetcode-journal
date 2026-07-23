class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        vector<vector<int>> dp (grid.size(), vector<int>(grid[0].size(),-1));
        int minn = INT_MAX;
        
         
         for( int i =0;i<grid[0].size();i++){
            minn=min(minn,solve(0,i,grid,moveCost,dp)) ;
           
         }
         return minn;
         
    }

    int solve( int y ,int x ,vector<vector<int>>& grid,vector<vector<int>>& moveCost,vector<vector<int>>& dp ){


       if ( y == grid.size()-1){
            return grid[y][x];
        }
        if( dp[y][x]!=-1) return dp[y][x];

        int minn =INT_MAX;
        
        int standing = grid[y][x];

        for( int i =0;i<grid[0].size();i++){

            int index = i ;

            int a  =  solve( y+1, i , grid,moveCost, dp)+ grid[y][x]+ moveCost[standing][i];
            if ( minn> a ){
                minn = a;
               
            }
        }

        return (dp[y][x]= minn );
    }
};