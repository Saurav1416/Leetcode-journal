class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        vector<double> ans;
        unordered_map<string,vector<pair<string,double>>>um;
       

        for( int i =0 ;i<equations.size();i++){

            string a = equations[i][0];
            string b = equations[i][1];
            um[a].push_back({b,values[i]});
            um[b].push_back({a,1/values[i]});
        }

        for( int i =0 ;i< queries.size();i++){
            if (um.find(queries[i][0]) == um.end() || um.find(queries[i][1]) == um.end()) {
                 ans.push_back(-1);
                  continue;
            }

             unordered_map<string,bool> visited;
             double anss = 1;
           if (dfs( queries[i][1],queries[i][0], um,anss ,visited))
            ans.push_back(anss);
            else ans.push_back(-1);
        }
        return ans;
        
    }

    bool dfs( string key ,string i , unordered_map<string,vector<pair<string,double>>> &um,
           double & ans, unordered_map<string, bool > &visited
    ){
        visited[i] = true;
        if ( i == key) return true;

        for( auto j : um[i]){
            if( !visited[j.first]){
                if(dfs( key,j.first,um ,ans,visited)){
                    ans *= j.second;
                    return true;
                }
           
            }
        }
        return false;
    }

};