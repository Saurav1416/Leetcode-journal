class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        // If endWord isn't present in wordList, no transformation is possible
        if (st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        // Erase to mark as visited
        st.erase(beginWord);

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord) return steps;

            // Try changing every character of the current word
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    
                    if (st.find(word) != st.end()) {
                        st.erase(word); // Mark visited by removing from set
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original; // Restore character
            }
        }

        return 0;
    }
};