class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0, j = 1;
        int start = 0;

        while(j < n){
            if(chars[j] != chars[j-1]){
                int cnt = j - start;
                chars[i++] = chars[j-1];
                if(cnt > 1){
                    string s = to_string(cnt);
                    for(char c : s){
                        chars[i++] = c;
                    }
                }

                start = j;
            }
            j++;
        }

        int cnt = j - start;
        chars[i++] = chars[j-1];

        if(cnt > 1){
            string s = to_string(cnt);
            for(char c : s){
                chars[i++] = c;
            }
        }

        return i;
    }
};