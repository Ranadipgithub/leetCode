class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> fq(26, 0);
        for(char ch: s){
            fq[ch-'a']++;
            if(fq[ch-'a'] > (n+1)/2) return "";
        }
        priority_queue<pair<int, int>> pq;
        for(int i = 0;i<26;i++){
            if(fq[i]>0) pq.push({fq[i], i});
        }

        string res = "";

        // aaaabbbcc
        // 4, a | (3, b) | (2, c)
        // res = a, prevFq = 3, prevCh = 0, (3, b) | (2, c)
        // res = ab, prevFq = 2, preCh = 1, (3, 1) | (2, c)
        while(pq.size() >= 2){
            auto it1 = pq.top();
            pq.pop();
            res += it1.second + 'a';

            auto it2 = pq.top();
            pq.pop();
            res += it2.second + 'a';
            
            it1.first--;
            it2.first--;
            if(it1.first > 0) pq.push(it1);
            if(it2.first > 0) pq.push(it2);
        }
        if(!pq.empty()) res.push_back(pq.top().second + 'a');
        return res;
    }
};