class Solution {
public:
    long f(int idx, int buy, vector<int>& prices, int fee,
           vector<vector<long>>& dp) {

        int n = prices.size();

        if (idx == n) {
            return 0;
        }

        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }

        long profit = 0;

        if (buy) {
            profit = max(
                -prices[idx] - fee + f(idx + 1, 0, prices, fee, dp),
                f(idx + 1, 1, prices, fee, dp)
            );
        } else {
            profit = max(
                prices[idx] + f(idx + 1, 1, prices, fee, dp),
                f(idx + 1, 0, prices, fee, dp)
            );
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<long>> dp(n, vector<long>(2, -1));

        return f(0, 1, prices, fee, dp);
    }
};