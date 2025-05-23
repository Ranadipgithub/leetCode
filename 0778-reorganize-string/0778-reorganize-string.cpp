class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        map<char, int> mpp;
        for (char ch : s) {
            mpp[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }

        string str = "";
        while (!pq.empty()) {
            auto [fq, ch] = pq.top();
            pq.pop();

            int len = str.size();
            if (len > 0 && str[len - 1] == ch) {
                if (pq.empty()) return ""; 

                auto [fq1, ch1] = pq.top();
                pq.pop();

                str += ch1;
                fq1--;
                if (fq1 > 0) pq.push({fq1, ch1});

                pq.push({fq, ch}); 
            } else {
                str += ch;
                fq--;
                if (fq > 0) pq.push({fq, ch});
            }
        }

        return str;
    }
};
