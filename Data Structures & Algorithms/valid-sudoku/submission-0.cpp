class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> v = {{0,0},{3,0},{6,0},{0,3},{0,6},{3,3},{3,6},{6,6},{6,3}};
        for(pair<int,int> p : v){
            int x = p.first;
            int y = p.second;
            vector<int> tmp(10,0);
            for(int i = x; i<x+3; i++){
                for(int j = y; j<y+3; j++){
                    cout << i << " " << j << endl;
                    if (board[i][j] != '.') {
                        tmp[board[i][j] - '0']++;
                    }   
                    // tmp[board[i][j] - '0']++;
                }
            }
            for(int i = 1; i < 10; i++ ){
                if(tmp[i] > 1) return false;
                tmp[i] = 0;
            }
        }
        vector<vector<int>> col(10,vector<int>(9,0));
        vector<vector<int>> row(10,vector<int>(9,0));
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if (board[i][j] != '.') {
                        row[board[i][j] - '0'][i]++;
                        col[board[i][j] - '0'][j]++;
                    }   
                // tmp[board[i][j] - '0']++;
            }
        }
        for(int i = 1; i < 10; i++ ){
            for(int j=0;j<9;j++){
                if(row[i][j] > 1 || col[i][j] > 1) return false;
            }
        }
        return true;
    }
};
