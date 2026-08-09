class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> stack;

        for( int i =0;i<asteroids.size();i++){

            if ( asteroids[i]<0){

                while(! stack.empty() && stack.back()>0 && stack.back()<abs(asteroids[i])){
                    stack.pop_back();
                    
                }
                if( !stack.empty() &&  stack.back()>=abs(asteroids[i])){
                    if(stack.back()==abs(asteroids[i]) )
                    stack.pop_back();

                    continue;
                }
            }
            stack.push_back(asteroids[i] );
        }

    

        return stack;
        
    }
};