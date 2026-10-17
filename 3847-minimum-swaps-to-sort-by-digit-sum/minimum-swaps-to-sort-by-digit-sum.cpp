class Solution {
public:

  
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> a =nums;
        vector<int>sum(n);

        for(int i=0;i<n;i++) {
             int x = nums[i];
             while(x){
             sum[i] += x%10;
            x/=10;
             }
        }

        

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(),[&](int  &x, int & y){
             if(sum[x] != sum[y])
            return sum[x] < sum[y];
       
         return nums[x] < nums[y];
        });
        
         vector<int> targetPos(n);
        for (int pos = 0; pos < n; pos++) {
            targetPos[indices[pos]] = pos;
        }
        vector<int>visited(n,0);
        int cycles=0;
        for( int i =0;i<n;i++){

            if( !visited[i]){
                cycles++;
                int j =i;
                while( !visited[j]){
                    visited[j]= true;
                    j= targetPos[j];
                }
            }
        }

        return n-cycles;


        
    }
};