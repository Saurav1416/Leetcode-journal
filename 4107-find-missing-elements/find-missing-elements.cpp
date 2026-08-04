class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        sort ( nums.begin(),nums.end());

        int minn = nums[0];
        int maxx = nums[nums.size()-1];

        vector<int> ans;
        int z =1;
        int n = nums.size();
        for( int i =minn+1;i<maxx;i++ ){
        if( z>=n-1 || ( z <n && nums[z]!=i)){
            ans.push_back(i);
            if( nums[z]<i)
            z++;
        }else if( z<n && nums[z]==i){
            z++;
        }
        


        }
        return ans;
        
    }
};