class Solution {
public:
    int singleNumber(vector<int>& nums) {

       
        // int ans =0;

        // for( int  i =0;i< 32 ;i++){
        //     int c =0;
        //     int t = 1<<i;
        //     for( int j =0;j<nums.size();j++){

        //          if( nums[j] & t) c++;
        //     }
        //     if( c%3!=0){
        //       ans = ans | t;
        //     }
        // }
        // return ans;    code in nlog is faster than this 


        int ones = 0;
        int twos = 0;

        for( int i =0;i<nums.size();i++){

            ones = (ones ^ nums[i])  & ~twos;
            twos = (twos ^ nums[i] ) & ~ones;
        }
        return ones;

        
    }

};