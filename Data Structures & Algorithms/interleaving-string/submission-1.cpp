class Solution {
public:
    vector<vector<int>> dp;
    int help(int i, int j, string &s1, string &s2, string &s3){
        if(i+j == (int)s1.size() + (int)s2.size()){
            return true;
        }
        if(i == s1.size()){
          return (s3.substr(i+j,s3.size()) == s2.substr(j,s2.size()));  
        }
        if(j == s2.size()){
            return (s3.substr(i+j,s3.size()) == s1.substr(i,s1.size()));
        }
        
        if(dp[i][j] !=-1) return dp[i][j];
        bool ans = false;
        if(s1[i] == s3[i+j]) ans = ans | help(i+1,j,s1,s2,s3);
        if(s2[j] == s3[i+j]) ans = ans | help(i,j+1,s1,s2,s3);
        return dp[i][j] = ans;  
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(n+m != s3.size()) return false;
        dp.resize(n,vector<int>(m,-1));
        return help(0,0,s1,s2,s3);
    }
};
