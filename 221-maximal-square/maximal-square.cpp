class Solution {
public:
    int solve( int i , int j , vector<vector<char>>& matrix,int &n ,int &m
    ,vector<vector<int>>&dp){
        if(  i>=n || j>=m) return 0;
        if( matrix[i][j]=='0') return 0;
        if( dp[i][j]!=-1) return dp[i][j];

        int a =  min( solve( i+1,j , matrix,n,m,dp), min( solve( i,j+1, matrix,n,m,dp), solve( i+1, j+1, matrix,n,m,dp)));

        return dp[i][j]= a+1;

    }
    int maximalSquare(vector<vector<char>>& matrix) {

        int ans =0;
        

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp( n, vector<int>( m , -1));

        for( int i =0;i<n;i++){
            for( int j =0;j<m;j++){

                if( matrix[i][j]=='1'){
                    ans = max( ans, solve( i ,j,matrix,n,m,dp));
                }
            }
        }
        return ans*ans;
        
    }
};