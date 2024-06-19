//https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int dp[1000+5][1000+5];
        
        // Initialize the first row and column of the dp array
        int i = 0;
        while(i <= W) {
            dp[0][i] = 0;
            i++;
        }

        i = 0;
        while(i <= n) {
            dp[i][0] = 0;
            i++;
        }

        // Filling the dp array
        i = 1;
        while(i <= n) {
            int j = 1;
            while(j <= W) {
                int v1 = dp[i-1][j]; // value without including the current item
                int v2 = 0;
                if(j - wt[i-1] >= 0) {
                    v2 = val[i-1] + dp[i-1][j - wt[i-1]]; // value including the current item
                }
                dp[i][j] = max(v1, v2);
                j++;
            }
            i++;
        }
        
        return dp[n][W];
    }
};
