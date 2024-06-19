//https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[100+1][100+1];

        int i=1;
        while(i<=n){
            int j=1;
            while(j<=m){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                if(i==1 and j==1){
                    dp[i][j]=1;
                }
                j++;
            }
            i++;
        }
        return dp[n][m];

    }
};
