class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int, pair<int,int>>um ;

        int prev = -1;
        int no  =0;
        int cnt = 0;

        for( int i =0;i<nums.size();i++){

            if( nums[i] &1 ){

                no++;
                
                um[no] = { i,prev};   // store index of this and prev odd no 
                prev =i;
            }
           

            if( no>= k){     //whenever count is greater or equal to k what we need to do is 
                             // just count gap bw  cnt -k  index and prev bcz remaining part 
                             // is same

                int a = no-k+1;

                cnt += um[a].first - um[a].second;
            }
            cout<<cnt;

        }
        return cnt ;
        
    }
};