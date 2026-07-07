class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,0);
        int ans = 0;
        for(int i = 0, j = 0; i<s.size(); i++){
            char x = s[i];
            // cout << x << " ";
            freq[x]++;
            while(freq[x] > 1){
                freq[s[j]]--;
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};
