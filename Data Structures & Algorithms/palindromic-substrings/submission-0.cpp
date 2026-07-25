class Solution {
public:
    vector<vector<int>> dp;
    bool help(string &s, int i, int j){
        if(i>=j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        help(s,i+1,j);
        help(s,i,j-1);
        bool f3 = (s[i]==s[j]) & help(s,i+1,j-1);
        return dp[i][j] = f3;
    }
    int countSubstrings(string s) {
        int n = s.size();
        dp.resize(n,vector<int>(n,-1));
        int res = 0;
        help(s,0,n-1);
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(i == j) res++;
                else res += dp[i][j];
            }
        }
        return res;
    }
};
