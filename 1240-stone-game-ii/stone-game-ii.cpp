class Solution {
public:
    int solve( int node ,vector<int>& piles , int m , vector<vector<int>>&dp,vector<int>& remaining){
        if( node >= piles.size()) return 0 ;

        if( dp[node][m]!=-1) return dp[node][m];

        

        int sum =0;
        int x = INT_MIN;
        int remain=0;
        for( int i = node ; i<2*m+node;i++){
            if( i<piles.size())
            {sum+=piles[i];
             remain = remaining[i];
            }
            int t = sum +remain-solve( i+1,piles,max( m,i-node+1),dp,remaining);
            x = max( x , t);

        }

       return  dp[node][m]=x; 
    }
    int stoneGameII(vector<int>& piles) {

        vector<vector<int>>dp (2* piles.size(), vector<int>(2*piles.size(),-1));

        int s =0;
        vector<int > remaining(piles.size(),0);

        for( int i =piles.size()-1;i>=0;i--){

            remaining[i]=s;
            s+=piles[i];
        }

        return solve( 0,piles,1,dp,remaining);
        
    }
};