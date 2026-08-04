class Solution {
public:
    int  solve( int i ,int t ,vector<int>& prices,vector<vector<int>>&dp){

        if( i>=prices.size()) return 0;

        if( dp[t][i]!=-1) return dp[t][i];

        int a = INT_MIN;

        if( t ==0){
            if( i != prices.size()-1)
            a = max( a, (solve( i+1,1,prices,dp) - prices[i]));   //buy  , cant buy on last day

            a = max(a,solve( i+1,0,prices,dp));   //skip buy

        }

        else {
            a = max( a, (solve( i+1,0,prices,dp)+ prices[i]));   //sell

            if( i!=prices.size()-1){
                a = max( a , solve( i+1,1,prices,dp));       //skip selling, cant skip to sell on last day
            }
        }

        return dp[t][i] = a;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>>dp( 2, vector<int>(n,-1));

       return solve (0, 0, prices,dp);
       
        
    }
};