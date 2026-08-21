class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {


        unordered_map<int,int> res;

        for( auto i: reservedSeats){

            int y = i[0];
            int x = i[1];

            if ( x>=2 && x<=9 ){

                res[y] |= ( 1<<x);  // we are doing OR on bits . setting bits 1 for col 
                             // if  col 3 is filled so it will set 3 bit 1
            }
        }

        int ans = ( n - res.size())*2;

        for ( auto &[row, mask] : res){

              bool left  = !(mask & ((1 << 2) | (1 << 3) | 
                                   (1 << 4) | (1 << 5)));

            bool right = !(mask & ((1 << 6) | (1 << 7) | 
                                   (1 << 8) | (1 << 9)));

            bool middle = !(mask & ((1 << 4) | (1 << 5) | 
                                     (1 << 6) | (1 << 7)));

            if( left && right){
                ans +=2;
            }
            else if ( left || right || middle){
                ans+=1;
            }
                        
        }
        return ans;
        
    }
};