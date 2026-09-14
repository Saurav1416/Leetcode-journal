class Solution {
public:

    int atmost(vector<int>&nums, int x){

        if( x <0)  return 0;

        int l =0;
        int sum =0;
        int ans = 0;
        for( int i =0;i< nums.size();i++){

            sum+= nums[i];

            while( sum >x){
                sum-=nums[l];
                l++;
                
            }
            ans+=i-l+1;

        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

    //    unordered_map<int,int> mp ;
    //    mp[0]=1;
    //    int sum =0;
    //    int ans=0;
    //    for( int i =0;i< nums.size();i++){

    //       sum += nums[i];

    //       if( mp.find( sum-goal)!=mp.end()){
    //           ans+=mp[sum-goal];
    //       }
    //         mp[sum]++;
    //       }
       
    //    return ans;

    //advance way 

    return atmost( nums, goal) - atmost( nums, goal-1);
        
    }
};