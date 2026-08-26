class Solution {
public:

    void solve(int  node, vector<int>& nums, vector<vector<int >>& ans,int n,vector<int>&helper ){

        if (node ==n){  ans.push_back( helper);
            return ;}

        ans.push_back(helper);

        for( int i =node;i<n;i++){

            if(i!=node && nums[i]==nums[i-1]) continue;

            helper.push_back(nums[i]);

            solve( i+1, nums,ans,n,helper);

            helper.pop_back();
        }


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;
      
        vector<int>helper;

        solve( 0,nums,ans,nums.size(),helper);

        return ans;

        
       
        
    }
};