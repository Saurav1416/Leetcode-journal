class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

        sort( costs.begin(),costs.end(),[](const auto&a , const auto&b){
            return (a[0]-a[1]<b[0]-b[1]);
        });

        int a =0;
        int ans =0;
        
        for( int i =0 ;i< costs.size();i++){
                if( a<costs.size()/2){
                    ans+=costs[i][0];
                    
                }
                else{
                    ans+=costs[i][1];
                }
                a++;
        }
        return ans;

        
    }
};