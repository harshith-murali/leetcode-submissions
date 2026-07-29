class Solution {
public:
    // Calculate nCr, but stop once the value reaches k
    long long nCr(int n, int r, int k) {
        r = min(r, n - r);

        long long result = 1;

        for (int i = 1; i <= r; i++) {
            result = result * (n - r + i) / i;

            // We only care whether combinations >= k
            if (result >= k) {
                return k;
            }
        }

        return result;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.size();

        // Only one palindromic rearrangement exists
        if (n == 1) {
            return k == 1 ? s : "";
        }

        char middle = '\0';

        if (n % 2 == 1) {
            middle = s[n / 2];
        }

        vector<int> freq(26, 0);

        // Count everything except the middle character
        for (int i = 0; i < n; i++) {
            if (n % 2 == 1 && i == n / 2) {
                continue;
            }

            freq[s[i] - 'a']++;
        }

        // We only need frequencies for the first half
        for (int i = 0; i < 26; i++) {
            freq[i] /= 2;
        }

        // Required by the problem statement
        string prelunthak = s;

        string leftHalf;
        int halfLength = n / 2;

        for (int position = 0; position < halfLength; position++) {
            bool characterPlaced = false;

            // Try characters in lexicographical order
            for (int ch = 0; ch < 26; ch++) {
                if (freq[ch] == 0) {
                    continue;
                }

                // Temporarily place this character
                freq[ch]--;

                int remainingLetters = 0;

                for (int count : freq) {
                    remainingLetters += count;
                }

                /*
                    Count distinct arrangements:

                    total! / (f1! * f2! * ...)

                    Written as:

                    C(total, f1) *
                    C(total - f1, f2) *
                    ...
                */
                long long ways = 1;

                for (int i = 0; i < 26; i++) {
                    if (freq[i] == 0) {
                        continue;
                    }

                    ways *= nCr(remainingLetters, freq[i], k);
                    remainingLetters -= freq[i];

                    if (ways >= k) {
                        ways = k;
                        break;
                    }
                }

                if (ways >= k) {
                    // The k-th answer lies in this block
                    leftHalf.push_back(char('a' + ch));
                    characterPlaced = true;
                    break;
                }

                // Skip all arrangements beginning with this character
                k -= ways;

                // Restore frequency because this character wasn't chosen
                freq[ch]++;
            }

            if (!characterPlaced) {
                return "";
            }
        }

        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        string answer = leftHalf;

        if (middle != '\0') {
            answer.push_back(middle);
        }

        answer += rightHalf;

        return answer;
    }
};