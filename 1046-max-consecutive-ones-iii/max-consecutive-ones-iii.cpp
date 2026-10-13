class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left =0;
        
        int count_zero=0;
        int ans=0;

        for( int i =0;i<nums.size();i++){

           if( nums[i]==0) count_zero++;
           while( count_zero>k){
            if( nums[left]==0) count_zero--;
            left++;

           }

           ans = max( ans, i-left+1);
        }
        return ans;
        
    }
};