class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(!st.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int steps = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string top = q.front();
                q.pop();

                if(top == endWord) return steps;
                for(int i = 0;i<top.size();i++){
                    for(char ch = 'a'; ch <= 'z';ch++){
                        string temp = top;
                        if(ch == top[i]) continue;
                        temp[i] = ch;
                        if(st.count(temp) && !visited.count(temp)){
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};