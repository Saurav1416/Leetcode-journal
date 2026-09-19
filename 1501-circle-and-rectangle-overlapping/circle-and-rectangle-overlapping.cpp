class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        long long dist = 0;
        if( x1> xCenter || x2< xCenter){
            dist += min( pow( xCenter-x1,2) , pow( xCenter-x2,2));

        }
        if( y1> yCenter || y2<yCenter){

            dist+= min( pow(yCenter-y1,2) ,pow( yCenter-y2,2));
        }
        return dist <= radius*radius;
        
    }
};