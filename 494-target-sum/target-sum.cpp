class Solution {
public:
     int solve( vector<int>&nums, int & target, int index, int s,int & sum,
     vector<vector<int>>&dp ){

        if( s== target and index == nums.size()) return 1;
        if( index==nums.size()) return 0;
        if( dp[index][sum+s]!=-1) return dp[index][sum+s];

        int ways =0;

            ways+= solve( nums,target, index+1,s+nums[index],sum,dp);
            ways+= solve( nums,target, index+1,s-nums[index],sum,dp);

            return dp[index][sum+s] =ways;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum =0;
        
        for( int i =0;i<nums.size();i++){
            sum+= abs(nums[i]);
        }
        if (abs(target) > sum) return 0;
        vector<vector<int>>dp( nums.size(),vector<int>(2*sum+1,-1));
       
        return  solve( nums, target, 0,0,sum,dp);
     
    }
};