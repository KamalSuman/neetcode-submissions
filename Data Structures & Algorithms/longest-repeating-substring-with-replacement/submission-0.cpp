class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int ans = 0;
        for(int i = 0, j = 0; i<s.size(); i++){
            freq[s[i]-'A']++;
            int maxi = *max_element(freq.begin(),freq.end());
            // cout << maxi << endl;
            while(i-j+1 - maxi > k){
                // cout << "HOla";
                freq[s[j]-'A']--;
                maxi = *max_element(freq.begin(),freq.end());
                j++;
            }    
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};
