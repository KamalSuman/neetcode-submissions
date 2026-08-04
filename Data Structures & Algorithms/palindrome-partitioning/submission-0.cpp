class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
    return true;
    }
    void help(string s, int i, vector<string> &res){
        string temp = "";
        for(int j = i; j<s.size(); j++){
            temp += s[j];
            if(isPalindrome(temp)){
                res.push_back(temp);
                help(s,j+1,res);
                res.pop_back();
            }
        }
        if(temp == "") ans.push_back(res);
    }
    vector<vector<string>> partition(string s) {
        vector<string> res;
        help(s, 0, res);
        return ans;
    }
};
