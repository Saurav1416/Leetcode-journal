class Solution {
public:
    int maxDepth(string s) {
          int l = 0;
     int r =0;
     int maxx = 0;

     for( auto i :s){

        if( i =='('){

            l++;
            maxx = max( maxx,l-r);
        }else if ( i==')'){
            r++;
        }
     }

     return maxx;
    }
};