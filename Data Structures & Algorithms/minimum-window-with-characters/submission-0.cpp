class Solution {
public:
    string minWindow(string s, string t) {
        int n = t.size();
        vector<int> freq(256);
        for(int i = 0; i < t.size(); i++){
            freq[t[i]]++;
        }
        int ans = 1001; 
        int x = -1, y = -1;
        for(int j = 0, i = 0; j < s.size(); j++){
            freq[s[j]]--;
            while(cool(freq)){
                if((j-i+1) < ans) {
                    ans = (j-i+1);
                    y = j;
                    x = i;
                }
                freq[s[i]]++;
                i++;
            }
        }
        string str = "";
        if(ans == 1001) return str;
        for(int i = x; i<=y; i++) str += s[i];
        return str;
    }
     bool cool(vector<int> &freq){
        for(int i = 0; i<256; i++){
            if(freq[i] >= 1) return false;
        }
        return true;
    }
};
