//https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution{   
public:
    bool isSubsetSum(vector<int> arr, int sum) {
        int n = arr.size();
        
        // Initialize dp array with all false
        bool dp[n+1][sum+1]; 
        
        // Initialize dp array base cases
        int i = 0;
        while (i <= n) {
            dp[i][0] = true;
            i++;
        }
        
        int j = 1;
        while (j <= sum) {
            dp[0][j] = false;
            j++;
        }
        
        // Populate the dp table using while loops
        i = 1;
        while (i <= n) {
            j = 1;
            while (j <= sum) {
                if (dp[i-1][j] == true) {
                    dp[i][j] = true;
                } else if (j >= arr[i-1] && dp[i-1][j - arr[i-1]] == true) { // Corrected index arr[i-1]
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
                j++;
            }
            i++;
        }
        return dp[n][sum];
    }
};
