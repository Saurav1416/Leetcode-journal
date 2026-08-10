class Solution {
public:
    int trap(vector<int>& height) {

        vector<pair<int,int>> stack;   //store value , index 
        pair<int,int>f={INT_MAX,-1} ;
        int water =0;
        pair<int,int>p;

        for( int i =0;i<height.size();i++){

            while( !stack.empty() && f.first<=height[i]){

                p = stack.back();
               
               
                    water+= (f.first-p.first);
                
                stack.pop_back();
            }
            if( stack.empty()){
                f= {height[i],i};
            }
            stack.push_back( {height[i],i});

        }
        int m=-1;
        while( !stack.empty()){

            p = stack.back();
            stack.pop_back();
            m = max( m,p.first);
            water+= m-p.first;

        }
        
        return water;
    }
};