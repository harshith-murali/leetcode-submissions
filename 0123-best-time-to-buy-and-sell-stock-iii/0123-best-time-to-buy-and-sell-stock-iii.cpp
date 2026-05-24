class Solution {
public:
    long f(int idx, int buy, vector<int>& prices, int cap,
           vector<vector<vector<long>>>& dp) {

        int n = prices.size();

        if (idx == n || cap == 0) {
            return 0;
        }

        if (dp[idx][buy][cap] != -1) {
            return dp[idx][buy][cap];
        }

        long profit = 0;

        if (buy) {
            profit = max(
                -prices[idx] + f(idx + 1, 0, prices, cap, dp),
                f(idx + 1, 1, prices, cap, dp)
            );
        } else {
            profit = max(
                prices[idx] + f(idx + 1, 1, prices, cap - 1, dp),
                f(idx + 1, 0, prices, cap, dp)
            );
        }

        return dp[idx][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<long>>> dp(
            n,
            vector<vector<long>>(2, vector<long>(3, -1))
        );

        return f(0, 1, prices, 2, dp);
    }
};