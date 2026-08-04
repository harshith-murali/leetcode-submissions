class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {};

        int smallest = INT_MAX;
        int largest = INT_MIN;

        for (int num : nums) {
            smallest = min(smallest, num);
            largest = max(largest, num);
        }

        vector<bool> present(largest - smallest + 1, false);
        for (int num : nums) {
            present[num - smallest] = true;
        }

        vector<int> result;
        for (int i = 0; i < present.size(); i++) {
            if (!present[i]) {
                result.push_back(smallest + i);
            }
        }

        return result;
    }
};