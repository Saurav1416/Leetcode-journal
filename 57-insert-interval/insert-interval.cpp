class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        
        vector<vector<int>>anss;
        int i =0;
        bool flag= false;
        while( i<intervals.size()){

            if(!flag &&intervals[i][0]>newInterval[1]){
                anss.push_back(newInterval);
                anss.push_back( intervals[i]);
                i++;
                flag= true;

            }
            else if(!flag && intervals[i][1]>=newInterval[0]){
                int a = min( intervals[i][0],newInterval[0]);
                int j = i;
                while( j<intervals.size() && intervals[j][0]<=newInterval[1]) j++;

                j= j-1;
                int b = max( intervals[j][1],newInterval[1]);
                anss.push_back({a,b});
                i = j+1;
                flag= true;

            }
            else{

                anss.push_back(intervals[i]);
                i++;
            }
        }
        if( flag == false ){
            anss.push_back( newInterval);
        }

        return anss;
        
    }
};