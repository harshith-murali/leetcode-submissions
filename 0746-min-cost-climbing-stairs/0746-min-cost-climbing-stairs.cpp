class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==0) return 0;
        int prev2 = 0 , prev = 0;
        for(int i=2; i<=n; i++){
            int curr = min(prev + cost[i-1] , prev2 + cost[i-2]);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};