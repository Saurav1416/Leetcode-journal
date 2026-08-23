class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        

        sort ( points.begin(),points.end());

        int darts=1;
        int cmp = points[0][1];

        for( int i =0;i<points.size();i++){

            if( cmp  <points[i][0]  ){
                darts++;
                cmp= points[i][1];

            }
            else{
                cmp =min(cmp,points[i][1]);
            }
        }
        return darts;
    }
};            