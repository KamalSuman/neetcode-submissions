class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        int l,k; 
        for(int i = 0; i < n; i++){
            int left = i, right = i;
            while(left>=0 && right < n && s[left] == s[right]){
                if(ans < right-left+1){
                    ans = right - left + 1;
                    l = left;
                    k = right;
                }
                left--;
                right++;
            }
            left = i; right = i+1;
            while(right < n  && left>=0 && s[left] == s[right]){
                if(ans < right-left+1){
                    ans = right - left + 1;
                    l = left;
                    k = right;
                }
                left--;
                right++;
            }
        }
        string str="";
        for(int j = l; j<=k; j++){
            str += s[j];
        }
        return str;
    }
};
