class Solution {
public:
    string frequencySort(string a) {
        // unordered_map<char,int> a;

        // for( int j=0;j<s.size();j++){
        //     a[s[j]]++;
        // }
        // vector<vector<char>> b(s.size()+1) ;
        // for(auto i: a){
        //     b[i.second].push_back(i.first);
        // }
        // string ans ="";
        // for( int i = b.size()-1;i>0;i--){
        //     for( char v: b[i]){
        //         ans.append(i,v);
        //     }
        // }
        // return ans;

         priority_queue<pair<int,char>>pq;
     unordered_map<char,int>um;

     for(auto i : a){
        um[i]++;
     }
     for(auto i :um){
        pq.push( {i.second,i.first});
     }
     string ans ="";
     while( !pq.empty()){

        auto i = pq.top();
        pq.pop();
        int freq= i.first;
        char elt = i.second;
        string s(freq,elt);
        ans+=s;

     }
     return ans;


    }
};