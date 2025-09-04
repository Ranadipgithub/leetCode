struct TrieNode {
    TrieNode* children[26];
    int end_count;

    TrieNode() {
        end_count = 0;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

void insert(TrieNode* root, const string& word) {
    TrieNode* curr = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (!curr->children[index]) {
            curr->children[index] = new TrieNode();
        }
        curr = curr->children[index];
    }
    curr->end_count++;
}

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void findWordsDfs(int r, int c, TrieNode* node, string& current_path,
                  vector<string>& results, const vector<vector<char>>& board,
                  vector<vector<bool>>& visited) {
    
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c]) {
        return;
    }

    char ch = board[r][c];
    TrieNode* next_node = node->children[ch - 'a'];

    if (next_node == nullptr) {
        return;
    }

    current_path.push_back(ch);
    visited[r][c] = true;

    if (next_node->end_count > 0) {
        results.push_back(current_path);
        next_node->end_count = 0;
    }

    for (int i = 0; i < 4; ++i) {
        findWordsDfs(r + dr[i], c + dc[i], next_node, current_path, results, board, visited);
    }

    visited[r][c] = false;
    current_path.pop_back();
}

vector<string> solve_problem(vector<vector<char>>& board, vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (const string& word : words) {
        insert(root, word);
    }

    vector<string> results;
    int rows = board.size();
    int cols = board[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    string current_path = "";

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            findWordsDfs(r, c, root, current_path, results, board, visited);
        }
    }
    
    sort(results.begin(), results.end());
    return results;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        return solve_problem(board, words);
    }
};