class Solution {
public:
    vector<vector<int>> vis;
    vector<vector<int>> dp;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int help(int i,int j, vector<vector<int>>& mat){
        if(vis[i][j]) return dp[i][j];
        vis[i][j] = true;
        int ans = 1; 
        for(auto d: dir){
            int l = i + d[0];
            int r = j + d[1];
            if(l < 0 || l >= mat.size() || r < 0 || r >= mat[0].size() || mat[i][j] >= mat[l][r]) continue;
            ans = max(ans , 1 + help(l,r,mat));
        }        
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vis.resize(n,vector<int>(m,0));
        dp.resize(n,vector<int>(m,-1));
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j]) ans = max(ans, help(i,j,matrix));
            }
        }
        return ans;
    }
};
