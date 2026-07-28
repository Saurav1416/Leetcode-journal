class Solution {
public:
    bool dfs(vector<int > &visited,vector<vector<int>>& graph ,
    int i ,vector<bool>& color){

        visited[i]= true;
        bool c = color[i];
        for( auto j :graph[i]){
             
             if (! visited[j]){
                color[j]=!c;
                bool d= dfs(visited,graph, j, color );
                if( d)  return true;

             }
              else if( color[j]==c){
                return true;
              }
             }
        
        return false;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int , vector<int >> adjlist;
        

        
        vector<bool> color( graph.size(),false);
        vector<int> visited( graph.size(),0);
        

        for( int  i=0 ;i< graph.size();i++){

            if( !visited[i]){
                color[i]= false;  //represent red
               bool d = dfs( visited, graph ,i,color);
               if ( d ) return false;   //odd cycle exist so not bipartite
            }
            
        }

    return true; 

    }
};