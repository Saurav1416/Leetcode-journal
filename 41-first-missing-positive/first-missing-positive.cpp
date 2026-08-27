class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        for( int i =0;i< n ;i++){
            if( nums[i]<0) 
                nums[i]=0;
        }

 


        for( int i =0;i<n;i++){

            int x = abs(nums[i]);

            if( (x-1)>=0 && (x-1)<n)
            { if ( nums[x-1]>=0){
                    if( nums[x-1]==0){
                        nums[x-1]=-(n+1);
                    }
                    else 
                    { nums[x-1]=-nums[x-1];}
            }}

          


        }

        for( auto i: nums){
            cout<<i;
        }



        int ans =n+1;
        for( int i =0;i< n;i++){

          
              
            if( nums[i]>=0){
                
                ans =i+1;
                break;
            }
        }
        return ans;
        
    }
};