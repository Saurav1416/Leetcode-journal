class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> um ;

        int sum =0;
        um[0]=-1;

        for(int i =0;i<nums.size();i++){

            sum+=nums[i];
            if( um.count( sum%k) ){
                if(i- um[sum%k]>=2)
                     return true;
            }

            else
            um[sum%k]=i;
        }

        return false;
        
    }
};