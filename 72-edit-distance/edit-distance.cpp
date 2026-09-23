class Solution {
public:
    int solve( int w1,int w2, string & word1, string & word2, vector<vector<int>>&dp){

        if( w1<0 && w2 <0 ) return 0;

        if( w1 <0) return w2+1;
        if( w2<0 ) return  w1+1;
        if( dp[w1][w2]!=-1)return dp[w1][w2];
        if( word1[w1]== word2[w2] ) return  dp[w1][w2] = solve( w1-1,w2-1,word1,word2,dp);

        // delete 
        int a = solve( w1-1, w2,word1,word2, dp);
        // replace
        int b = solve(w1-1,w2-1,word1,word2,dp );
        // insert
        int c = solve( w1, w2-1,word1,word2,dp);

        return  dp[w1][w2]=min(a,min( b,c))+1 ;




    }
    int minDistance(string word1, string word2) {
        int n =word1.size();
        int m = word2.size();
        vector<vector<int>>dp ( n, vector<int>(m,-1) );
        int w1 =word1.size()-1;
        int w2 = word2.size()-1;

        return solve( w1,w2, word1,word2,dp);


        
    }
};