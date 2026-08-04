class Solution {
public:
    int M = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long ans = 1;
        base %= M;
        while (exp > 0) {
            if (exp % 2 == 1) {
                ans = (ans * base) % M;
            }
            base = (base * base) % M;
            exp /= 2;
        }
        return ans;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int l = 0, r = n - 1;
        int result = 0;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                result = (result + power(2, r - l)) % M;
                l++;
            } else {
                r--;
            }
        }

        return result;
    }
};