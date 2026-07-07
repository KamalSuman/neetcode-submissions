class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        for(int i =0; i<s1.size(); i++) freq[s1[i]-'a']++;
        for(int j = 0, i = 0; j<s2.size(); j++){
            freq[s2[j]-'a']--;
            // if(cool(freq)) return true;
            // cout << endl;
            while(j - i + 1 > s1.size()){
                freq[s2[i]-'a']++;
                i++;
            }
            if(cool(freq)) return true;
        }
        return false;
    }
    bool cool(vector<int> &freq){
        for(int i = 0; i<26; i++){
            // cout << freq[i] << " " ;
            if(freq[i] !=0) return false;
        }
        return true;
    }
};
