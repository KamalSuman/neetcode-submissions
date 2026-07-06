class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        if (n < 3) return 0;

        vector<int> leftMax(n), rightMax(n);

        leftMax[0] = h[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], h[i]);
        }

        rightMax[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], h[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(leftMax[i], rightMax[i]) - h[i];
        }

        return ans;
    }
};