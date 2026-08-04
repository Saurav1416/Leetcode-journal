class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int minn =INT_MAX;
        int maxx = INT_MIN;

        unordered_map<int,int> um;

        for( int i =0 ;i< nums.size();i++){

            minn = min( nums[i], minn);
            maxx = max( nums[i],maxx);

            um[nums[i]]=1;
        }

        vector<int> ans;

        for( int i = minn+1;i<maxx;i++){

            if (um[i]==0){
                ans.push_back( i);
            }
        }

        return ans;
        
    }
};