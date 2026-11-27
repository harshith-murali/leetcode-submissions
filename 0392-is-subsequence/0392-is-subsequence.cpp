class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]].push_back(i);
        }

        int prev = -1;
        for (char ch : s) {
            if (mp.find(ch) == mp.end()) {
                return false;
            }

            const vector<int>& indices = mp[ch];
            auto it = upper_bound(indices.begin(), indices.end(), prev);

            if (it == indices.end()) {
                return false;
            }

            prev = *it;
        }

        return true;
    }
};