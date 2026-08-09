class Solution {
public:
    // int solve(vector<int>& nums,int i ,vector<int>&dp){

    //     if( i >= nums.size())
    //         return 0;
    //     if( dp[i]!=-1) return dp[i];
        
       

    //     int take = solve( nums, i+2,dp)+ nums[i];
    //     int skip = solve( nums, i+1,dp);

    //     return dp[i] = max( take,skip) ;
        

    // }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        // return solve( nums,0,dp);
        if( nums.size()==0) return -1;
        if(nums.size()==1){
            return nums[0];
        }
        

        
        dp[0 ]= nums[0];

        dp[1]= max( nums[0],nums[1]);
        for( int i =2;i<nums.size();i++){
            int take = dp[i-2]+ nums[i];
            int skip = dp[i-1];

            dp[i] = max( take,skip);

        }

        return dp[nums.size()-1];
        
    }
};