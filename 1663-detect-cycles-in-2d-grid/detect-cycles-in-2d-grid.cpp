class Solution {
public:

    pair<int,int> findp( int y, int x , vector<vector<pair<int,int>>>&parent){

        if( parent[y][x]!= pair<int,int>{y,x}){
            return parent[y][x]= findp( parent[y][x].first,parent[y][x].second,parent );
        }
        return parent[y][x] ;
    }

    bool unionn( int y1,int x1, int y2,int x2,vector<vector<pair<int,int>>>&parent){

        pair<int,int> a = findp(y1,x1,parent);
        pair<int,int> b = findp(y2,x2,parent);

        if (a==b) return true;

       parent[a.first][a.second] = b;

       return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

       vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m));
       

        
        for( int i =0;i<grid.size();i++){
            for( int  j =0;j<grid[i].size();j++){

                parent[i][j]= {i,j};
            }
        }

        for( int i =0;i<grid.size();i++){
            for( int  j =0;j<grid[i].size();j++){

               


               if( i+1<n && grid[i][j]== grid[i+1][j]){
                bool a = unionn( i,j, i+1,j,parent); 
                if( a ){
                    
                    return true;
                }
                }

                if( j+1<m && grid[i][j]== grid[i][j+1]){
                bool a = unionn( i,j, i,j+1,parent) ;
                if( a ){

                    
                    return true;
                }
                }



            }
        }
        return false;


        


        
    }
};