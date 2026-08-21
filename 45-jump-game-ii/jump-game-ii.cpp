class Solution {
public:
    int jump(vector<int>& nums) {

        
        int n = nums.size();
        if( n ==1) return 0;
        vector<int> dp ( nums.size(),-1);

        dp[n-1]= 0;

        for( int i = n-2;i>=0;i--){

            int minn =INT_MAX/2;
            for( int j = i+1;j<= i+nums[i] && j<n;j++){

                minn = min( minn , dp[j]);
            }
            dp[i]= minn+1;
        }
        return dp [0];
        
    }
};