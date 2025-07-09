class Solution {
public:
    vector<vector<string>> res;

    void dfs(string word, string beginWord, unordered_map<string, vector<string>>& parent, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            return;
        }

        for (string& p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, parent, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        unordered_map<string, vector<string>> parent;
        unordered_set<string> currentLevel, nextLevel, visited;

        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);

        bool found = false;
        while (!q.empty() && !found) {
            int size = q.size();
            currentLevel.clear();
            for (int i = 0; i < size; ++i) {
                string word = q.front(); q.pop();
                string original = word;

                for (int j = 0; j < word.size(); ++j) {
                    char ch = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[j] = c;
                        if (!dict.count(word) || visited.count(word)) continue;

                        if (!currentLevel.count(word)) {
                            q.push(word);
                            currentLevel.insert(word);
                        }
                        parent[word].push_back(original);

                        if (word == endWord) found = true;
                    }
                    word[j] = ch;
                }
            }
            for (auto& w : currentLevel) visited.insert(w);
        }

        if (!found) return {};

        vector<string> path = {endWord};
        dfs(endWord, beginWord, parent, path);
        return res;
    }
};
