class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        sort( intervals.begin(),intervals.end(),[](
            const auto & a, const auto &b){

                if( a[1]==b[1]){
                    return a[0]>b[0];   //not much necessary just for tie breaker 
                }
                return a[1]<b[1];
            });

        int first =-1;
        int second = -1;
        int ans =0;

        for( int i =0;i<intervals.size();i++){

            int l = intervals[i][0];
            int r = intervals[i][1];

            if( second < l){

                ans+=2;
                first = r-1;
                second = r;
            }
           if( first< l){
                 ans +=1;
                 first = second;
                 second = r;
            }
        }
        return ans;
        
    }
};