class Solution {
public:
    void swap(int &x,int &y){

        int temp =x ;
        x= y;
        y=temp;
    }
    void sortColors(vector<int>& nums) {
        int l =0;
        int r = nums.size()-1;

        for(int i =0;i<nums.size();i++){

            if( nums[i]==0){
                swap(nums[i],nums[l]);
                l++;
            }
            else if(nums[i]==2 && i<=r){
                swap(nums[i],nums[r]);
                r--;
                i--;
            }
        }
        return;
        
    }
};