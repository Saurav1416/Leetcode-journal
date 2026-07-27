class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int,int>>>adj;
        for( int i =0 ;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int weight = times[i][2];
            adj[u].push_back({v,weight});
        }

        vector<int>dist(n+1,INT_MAX);
        priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;

        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            auto a = pq.top (); pq.pop();
            int node = a.second;

            if( a.first> dist[node]) continue;
            
            for( auto i: adj[node]){
                if( dist[node]+i.second < dist[i.first]){
                    dist[i.first]= dist[node ] + i.second;
                    pq.push({dist[i.first],i.first});
                }
            }


        }
       int maxx= INT_MIN;
        for( int i =1 ;i<dist.size();i++){
            maxx = max( maxx, dist[i]);
        }

        return maxx==INT_MAX?-1:maxx;

        
    }
};


