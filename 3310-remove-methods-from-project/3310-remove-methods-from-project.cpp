class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> suspicious(n, false);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int ngb : adj[curr]) {
                if (!suspicious[ngb]) {
                    suspicious[ngb] = true;
                    q.push(ngb);
                }
            }
        }

        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            if (!suspicious[u] && suspicious[v]) {
                vector<int> all_methods(n);
                iota(all_methods.begin(), all_methods.end(), 0);
                return all_methods;
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};