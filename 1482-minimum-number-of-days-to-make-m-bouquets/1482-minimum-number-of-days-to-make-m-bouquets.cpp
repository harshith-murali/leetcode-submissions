class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int day) {
        int cnt = 0, noOfBouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                noOfBouquets += (cnt / k);
                cnt = 0;
            }
        }
        noOfBouquets += (cnt / k);
        return noOfBouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int s = *min_element(begin(bloomDay), end(bloomDay)), e = *max_element(begin(bloomDay), end(bloomDay));
        int ans = INT_MAX;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (possible(bloomDay, m, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};