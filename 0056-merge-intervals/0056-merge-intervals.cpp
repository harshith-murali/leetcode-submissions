class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size() - 1;) {
            int a = intervals[i][0];
            int b = intervals[i][1];
            int c = intervals[i + 1][0];
            int d = intervals[i + 1][1];

            if (c <= b) {
                intervals[i] = {a, max(b, d)};
                intervals.erase(intervals.begin() + i + 1);
            } else {
                i++;
            }
        }

        return intervals;
    }
};