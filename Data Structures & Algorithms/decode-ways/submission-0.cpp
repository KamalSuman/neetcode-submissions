class Solution {
public:
    vector<int> dp;
    int help(string &s, int j){
        if(j >= s.size()) return 1;
        if(dp[j] != -1) return dp[j];
        int ans = 0;
        if(s[j] == '0') return 0; 
        ans = help(s, j+1);
        if(j + 1 < (int)s.size()){
            int x = (s[j] -'0')*10 + (s[j+1]-'0');
            if(x <= 26) ans += help(s,j+2);
        } 
        return dp[j] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        dp.resize(n,-1);
        return help(s,0);
    }
};
