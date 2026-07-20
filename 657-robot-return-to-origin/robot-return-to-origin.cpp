class Solution {
public:
    bool judgeCircle(string s) {

         int y = 0;
  int x =0;

  for( auto i: s){

    if( i=='U'){
        y++;
    }else if( i=='D'){
        y--;
    }else  if( i=='R'){
        x++;
    }else{
        x--;
    }

  }

  if ( x==0 && y==0 ){
    return true;
  }
  return false;
        
    }
};