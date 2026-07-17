class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int > a ;
        vector<int >b ;
        int n = nums.size();

        for (int i =0 ;i<nums.size();i++){
            if ( nums[i]>0)
               a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
         
        for (int i =0;i< n ;i++){
             if( i%2 ==0){
                 nums[i]=a [i/2];
             }else{
                nums[i]= b[i/2];
             }
        }

        return nums;


    }
};