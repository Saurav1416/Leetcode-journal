class Solution {
public:
    struct dsu{
       
       vector<int> parent;

        dsu ( int n ){
            parent.resize(n+1);
            for( int i = 1 ;i<=n;i++){
                parent[i]=i;
            }
        }
        int findparent( int i ){
            if( parent[i]==i)
                return i ;
            else return parent[i]= findparent(parent[i]);

        }
        bool unions( int a , int b){
            int x = findparent(a);
            int y  = findparent(b);

            if( x==y ){
                return true;
            }
            if( x>y){
                swap ( x,y);
            }
            parent[x]=y;
            return false;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

       dsu nodeslist= dsu(n);
        pair<int,int> ans;
        vector<int>anss;

        for( auto i : edges){

            int x = i[0];
            int y = i[1];

            if( nodeslist.unions(x,y)){
                ans = {x,y};
            }
        }
        anss.push_back( ans.first);
         anss.push_back( ans.second);
         return anss;
    }
};