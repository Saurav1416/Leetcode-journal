class Solution {
public:
 
    int findp( int x,vector<int>&parent){

        if( parent[x]!=x){
            return parent[x] = findp(parent[x],parent);
        }
        return x;
    }

    void unite( int a ,int b,vector<int>&parent){
        int x = findp(a,parent);
        int y = findp(b,parent);
        if(x==y) return ;
        if( x>y) swap(x,y);
        parent[x]=y;
    }

    int removeStones(vector<vector<int>>& stones) {

       int  n = stones.size();
        vector<int>parent( n,-1);

        //here all indexes are stones and we are treating them as nodes. and joined nodes forms a connected comp . every connected comp can be reduced to single node . so if there are 3 connected comp in end then only 3 stone will remain

        for( int i =0;i<n;i++){
            parent[i]= i;
        }
        for( int i =0;i<n;i++ ){
            for ( int j =i+1;j<n;j++){

                if( stones[i][0]==stones[j][0]  || stones[i][1]==stones[j][1]){
                    unite( i,j,parent);
                }
            }
        }
        int connectedcomp =0;
        for( int i =0;i<n;i++){
            if( parent[i]==i)
              connectedcomp++;
        }
        return n-connectedcomp;




        
        
    }
};