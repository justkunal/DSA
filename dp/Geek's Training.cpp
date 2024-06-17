//https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n+2,vector<int>(4,0));
        dp[1][1]=points[0][0];
        dp[1][2]=points[0][1];
        dp[1][3]=points[0][2];
        
        int i=2;
        while(i<=n){
            dp[i][1]=points[i-1][0]+max(dp[i-1][2],dp[i-1][3]);
            dp[i][2]=points[i-1][1]+max(dp[i-1][1],dp[i-1][3]);
            dp[i][3]=points[i-1][2]+max(dp[i-1][2],dp[i-1][1]);
            i++;
        }
        return max({dp[n][1],dp[n][2],dp[n][3]});
    }
};
