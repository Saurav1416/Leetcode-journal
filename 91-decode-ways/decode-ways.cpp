class Solution {
public:
    //MEMOIZATION
    // int solve( string s , vector<int>&dp, int i){
    //     if ( i ==s.size()) return 1;
    //     if( s[i]=='0') return 0;
    //     if(dp[i]!=-1) return dp[i];
        
    //     int a = solve( s, dp, i+1);
    //     int b =0;
    //     if( s[i]=='1' ||s[i]=='2'){
    //         if ( i+1<s.size() && stoi(s.substr( i,2))<27){
    //           b=  solve( s,dp,i+2);
    //         }
    //     }
    //     return dp[i] = a+b;
    // }
    int numDecodings(string s) {
        vector<int>dp(s.size(),0);
        if( s[s.size()-1]=='0') dp[s.size()-1]=0;
        else dp[s.size()-1]=1;

        // return solve( s, dp,0);

       for( int i =s.size()-2;i>=0;i--){
            if( s[i]=='0') dp[i] = 0;
            else
{
            if( (s[i]=='1' ||s[i]=='2') && stoi(s.substr( i,2))<27){
            
                if( i+2<s.size())
                   dp[i]+=dp[i+2];
                else 
                   dp[i]++;
            }

            dp[i]+=dp[i+1];
}
       }
       return dp[0];

        
    }
};