class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int, pair<int,int>>um ;

        int prev = -1;
        int no  =0;
        int cnt = 0;

        for( int i =0;i<nums.size();i++){

            if( nums[i]%2==1){

                no++;
                
                um[no] = { i,prev};
                prev =i;
            }
           

            if( no>= k){

                int a = no-k+1;

                cnt += um[a].first - um[a].second;
            }
            cout<<cnt;

        }
        return cnt ;
        
    }
};