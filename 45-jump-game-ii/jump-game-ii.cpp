class Solution {
public:


        
        // int n = nums.size();
        // if( n ==1) return 0;
        // vector<int> dp ( nums.size(),-1);

        // dp[n-1]= 0;
        // int minn =INT_MAX/2;

        // for( int i = n-2;i>=0;i--){

            
        //     for( int j = i+1;j<= i+nums[i] && j<n;j++){

        //         minn = min( minn , dp[j]);
        //     }
        //     dp[i]= minn+1;
        //     minn = INT_MAX/2;
        // }
        // return dp [0];


    int jump(std::vector<int>& nums) {
        // Fast I/O micro-optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        // Iterate up to nums.size() - 1 because we don't need to jump once at the last index
        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);

            // Reached the end of the current jump coverage range
            if (i == current_end) {
                jumps++;
                current_end = farthest;
            }
        }

        return jumps;
    }
};
        
