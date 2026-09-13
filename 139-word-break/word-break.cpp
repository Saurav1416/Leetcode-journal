class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> set( wordDict.begin(),wordDict.end());
        vector<bool>dp ( n+1, false);
        dp[0]= true ;  // we are storing each elt in one index ahead 

        for( int i =1;i<=n;i++){

            for( int j =0;j<i; j++){

                if( dp[j]){  // are we are stroing each elt one index ahead so here we are talking about previous index 
                    string sub = s.substr( j,i-j);  //here j represent curr index on string 
                    if( set.count(sub)){
                        dp[i]= true;
                        break;
                    }
                }
            }
        }
        return dp [n];
    }
};