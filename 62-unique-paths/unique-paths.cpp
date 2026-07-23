class Solution {
public:
    // int solve( int x,int y , int n,int m ,vector<vector<int>>&dp){
    //     if( x==m-1 && y== n-1) return 1;
    //     if( dp[y][x]!=0) return dp[y][x];
    //     int a =0;

    //     if( y+1<n)
    //      a+= solve( x,y+1, n,m,dp);
    //     if( x+1<m)
    //      a+= solve( x+1,y,n,m,dp);
    //     dp[y][x]=a;
    //     return a;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return uq( 0,0,n,m,dp);



























    }
    int uq ( int x, int y , int xt,int yt, vector<vector<int>> &dp){

        if( x==xt-1 && y ==yt-1){
            return 1;
        }
        if( x>=xt || y>=yt){
            return 0;
        }
        if(dp[y][x]!=-1){
            return dp[y][x];
        }

        int ways =0;

        if(y+1<yt){ways+=uq(x,y+1,xt,yt,dp);}
         if(x+1<xt){ways+=uq(x+1,y,xt,yt,dp);}

         return  dp[y][x] = ways;
    }


};