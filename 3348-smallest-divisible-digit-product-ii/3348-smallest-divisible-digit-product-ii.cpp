class Solution {
public:
    typedef long long ll;
    
    int getMinDigits(ll num) {
        if (num <= 1) return 0;
        int count = 0;
        for (int digit = 9; digit >= 2; digit--) {
            while (num % digit == 0) {
                count++;
                num /= digit;
            }
        }
        return num == 1 ? count : 1e9;
    }

    string func(ll num, int len) {
        string str;
        for (int digit = 9; digit >= 2; digit--) {
            while (num % digit == 0) {
                str.push_back(digit + '0');
                num /= digit;
            }
        }
        while (str.length() < len) {
            str.push_back('1');
        }
        reverse(begin(str), end(str));
        return str;
    }

    string smallestNumber(string num, long long t) {
        int n = num.length();
        ll temp = t;
        for (int primeFact : {2, 3, 5, 7}) {
            while (temp % primeFact == 0) {
                temp /= primeFact;
            }
        }
        if (temp != 1) return "-1";

        vector<ll> remainingFactor(n + 1, t);
        int zeroIdx = n;

        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            if (digit == 0) {
                zeroIdx = i;
                break;
            }
            remainingFactor[i + 1] = remainingFactor[i] / std::gcd(remainingFactor[i], (ll)digit);
        }

        if (zeroIdx == n && remainingFactor[n] == 1) {
            return num;
        }

        for (int i = std::min(n - 1, zeroIdx); i >= 0; i--) {
            ll required = remainingFactor[i];
            int freeSlots = n - i - 1;

            int startDigit = (num[i] - '0') + 1;
            if (i < zeroIdx) {
                startDigit = (num[i] - '0') + 1;
            } else {
                startDigit = 1;
            }

            for (int digit = startDigit; digit <= 9; digit++) {
                ll furtherRequired = required / std::gcd(required, (ll)digit);
                if (getMinDigits(furtherRequired) <= freeSlots) {
                    string requiredNumber = func(furtherRequired, freeSlots);
                    return num.substr(0, i) + (char)(digit + '0') + requiredNumber;
                }
            }
        }

        return func(t, n + 1);
    }
};