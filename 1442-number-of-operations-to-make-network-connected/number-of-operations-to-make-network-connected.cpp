class Solution {
public:
     struct dsu{

        vector<int>parent ;

        dsu(int n){

            parent.resize(n);

            for( int i =0 ;i<n;i++){
                parent[i]=i;
            }
        }

        int findp( int x){

            if( parent[x]==x){
                return x;
            }

            return parent[x] = findp(parent[x]);
        }

        void unionn( int a,int b){
            int x = findp(a);
            int y = findp(b);

            if( x==y ) return ;

            if (x>y) swap (x,y);

            parent[x]= y;
        }



     };
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if ( connections.size()<n-1) return -1;
        vector<int> temp(n,0 );

        dsu D = dsu(n);

        
        for ( auto i: connections){

                if( D.findp(i[0])!= D.findp(i[1])){
                    D.unionn(i[0],i[1]);
                    temp[i[0]]=1;
                    temp[i[1]]=1;
                    
                }
                else{
                   
                    
                }

        }

         int components = 0;
        for (int i = 0; i < n; i++) {
        if (D.findp(i) == i)
        components++;
            }

        return components - 1;

    }
};