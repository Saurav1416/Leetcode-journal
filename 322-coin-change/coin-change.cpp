class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<long long> dp (amount+1,INT_MAX );
        dp[0]=0;

        for( int  i :coins){
            for( int j=i;j<=amount;j++){
                
                dp[j] = min(dp[j], dp[j-i]+1);
            }
        }
        if( dp[amount]== INT_MAX) return -1;
        return dp[amount];


    }
};