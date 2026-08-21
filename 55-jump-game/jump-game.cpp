class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if( nums[0]==0 && nums.size()!=1) return false;
        int step =nums[0];
        

        for( int i =1;i<nums.size();i++){
            
            step--;
            
            if( step<nums[i]){

                step = nums[i];
            }
            if( step<=0 && i!=nums.size()-1){
                return false;
            }
        }
        return true;
        
    }
};