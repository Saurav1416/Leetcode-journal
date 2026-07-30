class Solution {
public:
    struct DSU{
        vector<int> parent;

        DSU(int n ){
            parent.resize(n);
            for( int i =0;i<n;i++){
                parent[i]=i;
            }
        }

        int findp( int x){

            if ( parent[x]==x){
                return x;
            }

            return parent[x]= findp(parent[x]);
        }

        void unionn ( int a,int b){

            int x = findp(a);
            int y =findp(b);

            if( x==y) return;

            if( x>y){
                swap(x,y);
            }
            parent[x]=y;
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

       DSU dsu =  DSU( accounts.size());

        unordered_map<string,int> um;

        for( int i =0 ;i<accounts.size();i++){
            for ( int j =1;j<accounts[i].size();j++){

                if( um.count( accounts[i][j])){

                    dsu.unionn(i,um[accounts[i][j]]);
                }
                else{

                    um[accounts[i][j]]=i;
                }
            }
        }

        unordered_map< int, vector<string> > mergemap;

        for( auto i : um){

            string person = i.first;
            int  house = i.second;

            int parent = dsu.findp(i.second);

            mergemap[parent].push_back( person);
        }

        vector<vector<string>> finalans;


        for( auto i:mergemap){

            int x = i.first;
            vector<string >ans = i.second;

            sort( ans.begin(),ans.end());

           vector<string> temp;
            temp.push_back(accounts[x][0]); 
            for (auto &email : ans) temp.push_back(email);
            finalans.push_back(temp);
            
        }

        return finalans;
        
    }
};