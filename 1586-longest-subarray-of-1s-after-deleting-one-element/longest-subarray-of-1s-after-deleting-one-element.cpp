class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int prefix  =0;
        int suffix =0;

        int ans = 0 ;
        int isz =0;

        for( int i =0 ;i< nums.size();i++){

            if ( nums[i]==1){
                suffix ++;
            }
            else{

                isz =1;
                prefix = suffix;
                suffix = 0;
            }

            ans = max( ans, prefix+suffix);
        }

       return isz==1? ans:ans-1;
    }
};