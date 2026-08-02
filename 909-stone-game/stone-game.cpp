class Solution {
public:
    bool solve( int i ,int j , int t ,int alice, int bob,vector<int>& piles ,vector<vector<int>>&dp){

        if( i>j){
            if( alice>bob){
                return true;
            }
            else return false;
        }
        if( dp[i][j]!=-1){

            if( alice+dp[i][j]>bob){
                return true;
            }
            return false;
        }
        bool a = false;
        if( t==0){
            a |= solve( i+1, j,1,alice+piles[i],bob,piles,dp);
            a |= solve( i,j-1,1, alice+piles[j],bob,piles,dp);
        }
        else {
              a |= solve( i+1, j,0,alice,bob+piles[i],piles,dp);
            a |= solve( i,j-1,0, alice,bob+piles[j],piles,dp);


            dp[i][j]= alice -bob;

        }

        if( a ){
            return true;
        }
        return false;
    }
    bool stoneGame(vector<int>& piles) {

        vector<vector<int>>dp( piles.size(), vector<int>(piles.size(),-1));
        return solve( 0,piles.size()-1,0,0,0,piles,dp);
        
    }
};