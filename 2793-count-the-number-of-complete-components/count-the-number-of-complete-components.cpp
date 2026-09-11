class Solution {
public:
    int findp( int x, vector<int>& parent){

        if( parent[x]!=x){
            return parent[x]= findp(parent[x],parent);
        }
        return x;
    }

    void unionn( int a ,int b , vector<int>&parent,vector<int>&nodes,vector<int>&edges){

        int x = findp(a,parent);
        int y = findp(b, parent);

        if( x ==y){
            edges[x]++;
            return;
        }
        else if( x>y) swap(x,y);

        edges[y]+=edges[x] +1;
        nodes[y]+=nodes[x] ;
        parent[x]=y;
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<int >parent( n , -1);
        vector<int> nodes(n,1);
        vector<int>edgecount( n,0);
        for( int i =0;i<n ;i++){
            parent[i]= i;
        }

        for( auto i: edges){
            unionn( i[0],i[1],parent,nodes,edgecount);
        }
        int ans = 0;
        for( int i =0;i<n;i++){
            if( parent[i]==i ){
                int t = nodes[i];
                int expedges = (t*(t-1))/2;
                if( expedges==edgecount[i]) ans++;
                
            }

        }
        return ans;




    }
};