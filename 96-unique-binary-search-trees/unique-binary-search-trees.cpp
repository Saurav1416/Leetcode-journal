class Solution {
public:
    int numTrees(int n) {

        if( n ==0 || n==1) return 1;

        vector<int> dp( n+1,0);
        dp[0]=1;
        dp[1]=1;

        for( int i =2;i<=n;i++){

            int j =1;
            int sum =0;
            while( j<=i){
                int x = j-1;
                int y = i-j;
                sum +=dp[x] *dp[y];
                j++;
            }
            dp[i]=sum;
        }

        return dp[n];
        
    }
};