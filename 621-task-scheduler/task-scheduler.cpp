class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        

        // unordered_map<char,int> map;
        // for(auto i: tasks ){
        //     map[i]++;
        //     if( map[i]>maxx){
                
        //         maxx = map[i];
        //         count =1;
        //     }
        //     else if( map[i]==maxx){
        //         count++;
        //     }
        // }
        int freq[26]={0};
        for (const char c : tasks) {
            freq[c - 'A']++;
        }

        // 2. Find max frequency and its count in fixed 26 iterations
        int maxx = 0;
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > maxx) {
                maxx = freq[i];
                count = 1;
            } else if (freq[i] == maxx) {
                count++;
            }
        }
       int premut= (maxx-1)*(n+1) +count;
       int size = tasks.size();
       return max( size,premut);
    }
};