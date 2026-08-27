class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxwidth) {

        vector <string>ans;

        int i =0;
        int n = words.size();


        while(i<n ){

            int start = i;
            int currl = 0;

            while( i< n &&  currl < maxwidth){

                if( currl + words[i].size() + (i - start)> maxwidth) break;

                currl +=words[i].size();
                i++;
            }

             int cnt = i -start;
            string s="";

            if( cnt==1 || i==n ){
                for( int j = start ;j<i ;j++){

                    s+= words[j];
                    if( j !=i-1)
                    s+=' ';
                }

                s+= string ( maxwidth -s.size(), ' ');

            }

            else {

                int spaces = maxwidth-currl;
                int spw=  spaces/ (cnt-1);
                int rem = spaces%( cnt -1);
                for( int j =start ;j<i ;j++){

                    s +=words[j];
                    if( j!=i-1){

                        s+= string( spw,' ');
                       s+= string( ( j-start<rem?1:0),' ');
                    }
                }
            }
            ans.push_back(s);
        }

        return ans;
        
    }
};