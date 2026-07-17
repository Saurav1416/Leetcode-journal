class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int a =0;
        int maxx =0;
        

        for(int i =0;i< nums.size();i++){

            if( nums[i]!=1){
                a=i+1;
            }
            else{
                maxx = max(maxx,i-a+1);

            }
        }
        return maxx;
    }
};