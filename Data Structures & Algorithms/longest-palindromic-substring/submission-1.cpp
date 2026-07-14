class Solution {
public:
    int ans = 1;
    int l = 0;
    int k = 0;
    vector<vector<int>> dp;
    bool help(string &s, int i, int j){
        if(i>=j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        help(s,i+1,j);
        help(s,i,j-1);
        bool f3 = (s[i]==s[j]) & help(s,i+1,j-1);
        if(f3 && j-i+1 > ans){
            ans = j-i+1;
            l = i;
            k = j;
        }
        return dp[i][j] = f3;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        dp.resize(n,vector<int>(n,-1));
        help(s,0,n-1);
        string res="";
        for(int j = l; j<=k; j++){
            res += s[j];
        }
        return res;
    }
};
