class Solution {
public:
    bool isAlphanumeric(char s){
        int ascii = s + 0;
        if (ascii < 48 || (ascii > 57 && ascii < 65) || (ascii > 90 && ascii < 97) || ascii > 122 ) return false;
        return true;
    }
    bool isPalindrome(string s) {
        string s1;
        for(int i = 0; i<s.size(); i++){
            if(!isAlphanumeric(s[i])) continue;
            s1 += tolower(s[i]);
        }
        string s2 = s1;
        // cout << 'z' + 0 << endl;
        // cout << s1 << " ";
        reverse(s1.begin(),s1.end());
        return (s1 == s2);
    }
};
