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

        for ( auto i : res){

            bool left = !(1<<2&i.second || 1<<3&i.second 
                            || 1<<4&i.second || 1<<5&i.second);

            bool middle =!(1<<4&i.second ||1<<7&i.second 
                            || 1<<6&i.second || 1<<5&i.second);

            bool right = !(1<<9&i.second || 1<<7&i.second 
                            || 1<<6&i.second || 1<<8&i.second);

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