class Node {
public:
    bool exist = false;
    string word;
    vector<Node*> next;

    Node() {
        next.resize(26, nullptr);
    }

    Node* get(char c) {
        int idx = c - 'a';

        if (idx < 0 || idx >= 26)
            return nullptr;

        return next[idx];
    }

    void put(char c, Node* node) {
        next[c - 'a'] = node;
    }
};


class Solution {
public:

    vector<vector<int>> dir{{-1,0}, {1,0}, {0,-1}, {0,1}};

    void dfs(int i, int j,
             vector<vector<char>>& board,
             vector<vector<int>>& vis,
             Node* curr,
             vector<string>& ans) {

        char c = board[i][j];

        Node* child = curr->get(c);

        if (child == nullptr)
            return;

        // Found a complete word
        if (child->exist) {
            ans.push_back(child->word);
            child->exist = false;
        }

        vis[i][j] = 1;

        int n = board.size();
        int m = board[0].size();

        for (auto &d : dir) {

            int x = i + d[0];
            int y = j + d[1];

            if (x < 0 || x >= n ||
                y < 0 || y >= m ||
                vis[x][y])
                continue;

            dfs(x, y, board, vis, child, ans);
        }

        vis[i][j] = 0;
    }


    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        Node* root = new Node();

        // Build Trie
        for (string &word : words) {

            Node* curr = root;

            for (char c : word) {

                if (curr->get(c) == nullptr) {
                    curr->put(c, new Node());
                }

                curr = curr->get(c);
            }

            curr->exist = true;
            curr->word = word;
        }

        vector<string> ans;

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Start DFS from every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (root->get(board[i][j]) != nullptr) {

                    dfs(i, j, board, vis, root, ans);
                }
            }
        }

        return ans;
    }
};