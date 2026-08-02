class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> count(26, 0);

        for (char ch : s) {
            count[ch - 'a']++;
        }
        for (char ch : t) {
            count[ch - 'a']--;
        }

        return all_of(begin(count), end(count), [](int element) {
            return element == 0;
        });
    }
};