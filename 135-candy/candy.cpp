class Solution {
public:
    int candy(vector<int>& ratings) {
       

        int candyreq =1;
        int mincandy =1;
        int ans =1;
        
        int lastc =-1;

        for(int i =1;i<ratings.size();i++){

                if( ratings[i]<ratings[i-1]){
                    ans+=candyreq+1;
                    candyreq=candyreq+1;
                    mincandy=1;
                    if( candyreq==lastc){
                        ans+=1;
                        lastc++;
                    }
                    

                }
                else if( ratings[i]>ratings[i-1]){
                    ans+=mincandy+1;
                    mincandy = mincandy+1;
                    candyreq=0;
                   
                    lastc= mincandy;
                }
                else{
                    
                    ans+=1;
                    candyreq=1;
                    lastc=-1;
                    mincandy=1;

                }
        }
        return ans;
        
    }
};