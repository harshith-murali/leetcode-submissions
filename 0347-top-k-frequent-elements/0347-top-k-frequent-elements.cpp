class Solution {
public:
    using pii = pair<int, int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        // Min-heap storing {frequency, element}
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (auto& [num, freq] : mp) {
            pq.push({freq, num});
            if (pq.size() > k) {
                pq.pop(); // Evict the element with the smallest frequency
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};