class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        unordered_map<int,int> um  ;      //stores sum ,indes
        int a =0;
        for( auto i: nums){
            a +=i;
        }
        int  target = a- x;
        if (target == 0)
           return nums.size();
        um[0]=-1;
        a =0;
        int ans= -1;

        for( int i =0;i<nums.size();i++){
            a+=nums[i];
            if( um.find(a-target)!=um.end()){

                ans = max( ans, i-um[a-target]);
            }
           
            if(! um.count(a)){
                um[a]=i;
            }
        }

        return ans==-1?ans:nums.size()-ans;
        
    }
};