class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int j = n-1;
        for(int i = n-2; i>=0; i--){
            if((j - i ) - nums[i] <= 0) {
                j = i;
            } 
        }
        return !j ? true : false;
    }
};
