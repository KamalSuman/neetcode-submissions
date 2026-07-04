class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set <int> s(nums.begin(),nums.end());
        int ans = 1;
        
        for(int i = 0; i< nums.size(); i++){
            if(s.find(nums[i]-1) != s.end()) continue;
            else {
                int j = 1; int t = 1;
                while(s.find(nums[i] + j) != s.end()){
                    j++;
                    t = t + 1;
                }
                ans = max(ans,t);
                j = 1;
            }
        }
        return ans;
    }
};
