class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return 0;

        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);

        int cnt = 1; 

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string s = q.front();
                q.pop();
                if (s == endWord) return cnt;

                for (int i = 0; i < s.size(); i++) {
                    string str = s;
                    for (char j = 'a'; j <= 'z'; j++) {
                        str[i] = j;
                        if (st.count(str) && !visited.count(str)) {
                            q.push(str);
                            visited.insert(str); 
                        }
                    }
                }
            }
            cnt++;
        }

        return 0;
    }
};
