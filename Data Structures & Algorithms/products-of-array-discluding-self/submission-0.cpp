class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int mul = 1;
        vector<int> ans(n,0);
        int n_zero = 0;
        for (int i = 0; i<n; i++){
            if(nums[i]==0) n_zero++;
            mul *= nums[i]; 
        }
        if(n_zero>1) return ans;
        if(n_zero==1) {
            int p1 = 1; int j = 0;
            for(int i = 0; i<n;i++){
                
                if(nums[i] == 0){
                    j = i;
                    continue;
                }  
                p1 *= nums[i];
            }
            ans[j] = p1;
        }
        else {
            for(int i = 0; i < n; i++){
                ans[i] = (mul / nums[i]);
            }
        }
        return ans;
    }
};
