class Solution {
public:

    int findp( int x, vector<int>&parent){

        if(parent[x]!=x ){
           return parent[x]= findp(parent[x],parent);
        }
        return x;
    }

    void unionn(int a, int b , vector<int>&parent,vector<long long>&size){
        int x = findp(a,parent);
        int y = findp( b, parent);
        if( x == y ) return ;

        if( x>y){
            swap( x,y);
        }
        size[y]+= size[x];

        parent[x]= y;
        return ;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<int> parent( n ,-1);
        for( int i =0;i<n;i++){
            parent[i] =i;
        }

        vector<long long > size( n ,1);
        unordered_map<int,int>visited;
        long long ans=0;
        int numb = n;

        for( int i =0;i< edges.size();i++){
           unionn( edges[i][1],edges[i][0],parent,size);
        }

        for( int i =0;i<n;i++){
            int t = findp( parent[i],parent);
            if( !visited[t])
            {visited[t] =1;
             long long c = size[t];
            numb-= c;
            ans+= (numb*c);}

        }
        return ans;
        

        
    }
};