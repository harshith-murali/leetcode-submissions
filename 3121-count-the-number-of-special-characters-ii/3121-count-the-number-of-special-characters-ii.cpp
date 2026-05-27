class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, -1), upper(26, -1);
        int cnt = 0;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            char ch = word[i];

            if (islower(ch)) {
                lower[ch - 'a'] = i;
            } else {
                if (upper[ch - 'A'] == -1)
                    upper[ch - 'A'] = i;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (lower[i] != -1 && upper[i] != -1 && lower[i] < upper[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};