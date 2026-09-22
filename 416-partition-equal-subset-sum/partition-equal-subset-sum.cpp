class Solution {
public:
    // int  solve( int i , int t , int sum , int &n, vector<vector<int>>&dp,
    // vector<int>&nums){

    //     if( t == sum) return dp[i][t]= 1;
    //     if( i>=n) return 0;

    //     if( dp[i][t]!=-1) return dp[i][t];

    //     //skip
    //     bool a =false;
    //     bool b = false;
    //     a = solve( i+1, t,sum,n,dp,nums);
    //     b = solve( i +1, t+nums[i], sum-nums[i],n,dp,nums) ;

    //     return dp[i][t]= (a |b);
    // }


    // this approachs works but better memoization would be if we only look up to sum /2 cuz to partition in 2 set both sum has to be totalsum/2

    bool canPartition(vector<int>& nums) {
        int sum =0; 
        int n = nums.size();
        for( int i =0;i<nums.size();i++){

            sum+= nums[i];
        }
        if( sum %2!=0) return false;

        // vector<vector<int>>dp( n+1,vector<int>( sum+1,-1));
        vector<bool >dp ( sum/2 +1, false);
        dp[0] = true;

        for( int i :nums){
            for( int j = sum/2;j>=i;j--){

                dp[j] = dp[j]|| dp[j-i];
            }
        }
        return dp[sum/2];
        
        
    }
};