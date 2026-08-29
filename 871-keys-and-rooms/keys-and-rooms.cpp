class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {


        vector<bool> v( rooms.size(), false);
        v[0]= true;

        queue<int> q;

        for( int i=0;i< rooms[0].size();i++){
            q.push( rooms[0][i]);
            v[rooms[0][i]]= true;

        }

        while( !q.empty()){

            int size = q.size();

            for( int i =0;i< size;i++){

                int b = q.front();
                q.pop();

                for( int j =0;j<rooms[b].size(); j++){
                     int t = rooms[b][j];

                    if(! v[t]){
                        q.push( t);
                        v[t] = true;
                    }
                }
            }
        }

        for( int i =0;i< v.size();i++){
            
            if( !v[i]){
                return false;
            }
        }
        return true;
        
    }
};