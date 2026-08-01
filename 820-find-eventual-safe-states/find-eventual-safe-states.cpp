class Solution {
public:
     int  solve( int node,vector<int>& s,vector<vector<int>>& graph){

        if ( s[node]==2) {
            return 3;
        }
        if( s[node]==3) return 3;
        if ( s[node]==1) return 1;

        if ( graph[node].size()==0){
            s[node]=1;        // 1 represent safe;
            return 1;
        }

        s[node]=2;        //2 represent dont know ;
        int t=0 ;
        for ( auto i: graph[node]){

          t = max( t,solve( i,s,graph))  ;
        }



        if( t ==1){
            s[node]=1;
            return 1;
        }
        else {

            s[node] =3;
            return 3;
        }





       
     }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n = graph.size();
        vector<int> s(n,0);
        
        vector<int>ans;

        for( int i =0 ;i<n;i++){

           
                solve( i, s,graph);
            
        } 

        for( int i =0 ;i< s.size();i++){
            if (s[i]==1){
                ans.push_back( i);
            }

        }

        return ans;
        
    }
};