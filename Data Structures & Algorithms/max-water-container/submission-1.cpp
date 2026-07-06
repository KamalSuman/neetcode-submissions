class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int ans = min(heights[0],heights[n-1]) * (n-1);
        for(int i = 0, j = n - 1; i<j; ){
            int area = min(heights[i],heights[j]) * (j-i);
            ans = max(ans, area);
            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return ans;
    }
};
