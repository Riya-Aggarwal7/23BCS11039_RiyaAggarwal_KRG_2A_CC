class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int maxi = 0;

            for (int len = 1; len <= k && i - len >= 0; len++) {
                maxi = max(maxi, arr[i - len]);
                dp[i] = max(dp[i], dp[i - len] + maxi * len);
            }
        }

        return dp[n];
    }
};
