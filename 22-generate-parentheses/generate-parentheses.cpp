class Solution {
public:
    void solve( int left, int right, int n , vector<string> &ans, string st){

        if ( right==n ) { 
            ans.push_back(st );
            return ;
        }

        if( left<n  ){
            
            solve( left+1,right, n ,ans, st+'(');
        }
        if( left>right){
           
            solve( left, right+1, n ,ans,st+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string st="";
        solve( 0,0,n,ans,st);
        return ans;


        
    }
};