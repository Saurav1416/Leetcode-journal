class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if( source == target ) return 0;

        unordered_map<int,vector<int>> adj;

        for( int i =0;i<routes.size();i++){

            for( int j =0 ;j<routes[i].size();j++){

                int x = routes[i][j];

                adj[x].push_back( i);
            }
        }

        queue<int> q;
        vector< bool> v ( routes.size(), false);
        for( auto i :adj[source] ){

            q.push(i);
            v[i] =true;
        }

       
       
        
        int cnt=0 ;
       
        while( !q.empty()){

            cnt++;
            

            int size = q.size();
            

            for( int i =0;i<size;i++){

                int a = q.front();
                q.pop();
               
                    for( int j =0;j<routes[a].size();j++){

                        

                        int x = routes[a][j];
                        if( x ==target){
                            return cnt;
                        }

                        for( auto y : adj[x]){

                            if( !v[y]){
                                q.push(y);
                                v[y] = true;
                            }
                        }


                    }
                
            }
        }
        return -1;
        
    }
};