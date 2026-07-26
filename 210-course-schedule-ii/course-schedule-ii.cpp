class Solution {
public:

    bool dfs( vector<int > & visited, vector<vector<int>>& adjlist,vector<int>&ans,int i
    , vector<int>&dfsvisited
     ){


        visited[i] = true;
        dfsvisited[i]= true;

        for( auto j :adjlist[i]){
            if(! visited[j]){
               if (dfs( visited,adjlist,ans,j,dfsvisited)){
                return true;
               }
            }
            else if ( dfsvisited[j]){
                return true;
            }
        }
        ans.push_back( i);
        dfsvisited[i]=false;
        return false;
    }



    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;

        vector<vector<int>> adjlist(numCourses,vector<int>{});

        for( auto i: prerequisites){

            int x = i[0] ; // node from which we can go 
            int y = i[1]  ;

            adjlist[x].push_back(y);
   
        }
        vector<int> visited( numCourses,0);
        vector<int> dfsvisited(numCourses,0);
        
        for( int i =0;i< adjlist.size();i++){

            if( !visited[i ]){
                if (dfs(visited, adjlist, ans, i, dfsvisited)) {
                    return {};
                }
            }

        }
        
        return ans;
        
    }
};