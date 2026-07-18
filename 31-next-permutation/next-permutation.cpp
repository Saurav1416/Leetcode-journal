class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int j =nums.size()-1;

    while(j>0 && nums[j]<=nums[j-1]){
        j--;
    }
    if( j==0){
        int l =0;
        int r = nums.size()-1;
        while(l<r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }else{
        int x = nums[j-1];
       int t = nums.size()-1;
       while( nums[t]<=nums[j-1]){
        t--;
       }
       swap( nums[j-1],nums[t]);
       sort( nums.begin()+j,nums.end());
    }

    

       
    }
};