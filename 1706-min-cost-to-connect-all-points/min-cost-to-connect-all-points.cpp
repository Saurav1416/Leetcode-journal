class Solution {
public:
    
    // here ques asked for manhattan dist not euclidean so we dont need square,square root 
    int minCostConnectPoints(vector<vector<int>>& points) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       
         int n = points.size();

        pq.push({0,0});
        vector<bool>v(n,false);

        int ans = 0;
        while( !pq.empty()){
            auto a = pq.top();
            pq.pop();

            if( v[a.second]){
                continue;
            }
            v[a.second]= true;
            ans+=a.first;

            for(int i =1;i<n;i++){

                if( !v[i]){
                     int dist = abs(points[a.second][0]- points[i][0])+abs(points[a.second][1]- points[i][1]);
                     pq.push( {dist,i});
                }
            }
        }
        return ans;
        
    }
};