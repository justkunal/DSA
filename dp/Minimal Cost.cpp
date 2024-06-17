//https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n, INT_MAX);  // Initialize dp array with INT_MAX
        dp[0] = 0;  // Starting point, no cost

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (i - j >= 0) {
                    dp[i] = min(dp[i], dp[i - j] + abs(height[i] - height[i - j]));
                }
            }
        }
        return dp[n - 1];  // Return the minimum cost to reach the last stone
    }
};
