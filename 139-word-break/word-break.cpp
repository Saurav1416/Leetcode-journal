class Solution {
public:
    bool solve( int index , string &s, vector<int> & dp,unordered_set<string>& set ){

        if( index ==s.size()) return true;

        if(dp[index]!=-1) return dp[index];

        for( int j =index ;j<s.size();j++){
            string sub = s.substr( index, j-index+1);
            if( set.count(sub) && solve( j+1,s,dp ,set ) ){
                return dp[index] = 1;
            }
        }
        return dp[index]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // int n = s.size();
        // unordered_set<string> set( wordDict.begin(),wordDict.end());
        // vector<bool>dp ( n+1, false);
        // dp[0]= true ;  // we are storing each elt in one index ahead 

        // for( int i =1;i<=n;i++){

        //     for( int j =0;j<i; j++){

        //         if( dp[j]){  // are we are stroing each elt one index ahead so here we are talking about previous index 
        //             string sub = s.substr( j,i-j);  //here j represent curr index on string 
        //             if( set.count(sub)){
        //                 dp[i]= true;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return dp [n];

        int n = s.size();
        unordered_set<string> set( wordDict.begin(),wordDict.end());
        vector<int>dp ( n+1, -1 );
        return solve( 0, s, dp,set);
    }
};