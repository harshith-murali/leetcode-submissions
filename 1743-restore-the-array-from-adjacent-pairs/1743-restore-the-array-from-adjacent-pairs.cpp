class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;

        for (const auto& pair : adjacentPairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }

        int start = 0;
        for (const auto& [node, neighbors] : adj) {
            if (neighbors.size() == 1) {
                start = node;
                break;
            }
        }

        int n = adjacentPairs.size() + 1;
        vector<int> result(n);
        result[0] = start;
        int prev = INT_MIN;

        for (int i = 1; i < n; i++) {
            const auto& neighbors = adj[result[i - 1]];
            for (int next : neighbors) {
                if (next != prev) {
                    result[i] = next;
                    prev = result[i - 1];
                    break;
                }
            }
        }

        return result;
    }
};