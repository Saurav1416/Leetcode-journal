class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist( n,vector<int>(m,INT_MAX));
        vector<vector<bool>>v( n , vector<bool>(m,false));

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
             greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,0}});
        vector<int>dy {1,0,-1,0};
        vector<int>dx {0,1,0,-1};
        int ans = 0;
        while( !pq.empty()){
            auto[ w,r] =pq.top();
            int y = r.first;
            int x = r.second;
            pq.pop();
            if(v[y][x]) continue  ;
            v[y][x]= true;
            ans =max( w,ans);
            if( y == n-1 && x == m-1) return ans;

            for( int i =0;i<4;i++){

                int ny = y +dy[i];
                int nx = x + dx[i];

                if ( ny>=0 && ny<n && nx >=0 && nx<m && !v[ny][nx]){
                    int d =max( abs(heights[y][x]- heights[ny][nx]),w);
                    pq.push({d,{ny,nx}});
                }

            }
        }
        return ans;
        
    }
};