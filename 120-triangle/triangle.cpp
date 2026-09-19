class Solution {
public:
    // int solve( int i , int j ,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    //     if( i ==triangle.size()-1) return triangle[i][j];
    //     if( dp[i][j]!=INT_MIN) return dp[i][j];
    //     //
    //     int a  = INT_MAX;
    //     int b = INT_MAX;
    //     a = solve ( i+1, j ,triangle,dp) ;
    //     b = solve(i +1,j+1, triangle,dp);
       
    //    return dp[i][j] =min(a,b)+  triangle[i][j];
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n =triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        // return solve( 0,0,triangle,dp);


        int s = triangle[0][0] ;
        dp[0][0]= s;
        for( int i =1;i< n;i++){
            
            for( int j =0;j< triangle[i].size();j++){
                if( j-1>=0)
                dp[i][j] = min( dp[i-1][j],dp[i-1][j-1]) + triangle[i][j];
                else 
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
        }
        int  ans = INT_MAX;
        for( int i  =0;i<m;i++){
            ans = min( ans,dp[n-1][i]);
        }
        return ans;


        

        
    }
};