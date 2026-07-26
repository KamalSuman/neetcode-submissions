class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pref = 1, suff = 1, ans = -10;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                pref = 1;
                suff = 1;
                ans = max(ans,0);
                continue;
            }
            suff = suff * nums[n - 1 - i];
            pref = pref * nums[i];
            ans = max(ans,max(suff,pref));
        }
        return ans;
    }
};
