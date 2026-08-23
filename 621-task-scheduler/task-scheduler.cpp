class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int maxx =-1;
        int count = 0;

        unordered_map<char,int> map;
        for(auto i: tasks ){
            map[i]++;
            if( map[i]>maxx){
                
                maxx = map[i];
                count =0;
            }
            if( map[i]==maxx){
                count++;
            }
        }
       int premut= (maxx-1)*(n+1) +count;
       int size = tasks.size();
       return max( size,premut);
    }
};