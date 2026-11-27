class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        int ans = INT_MIN;
        int cnt = 0;
        while(r < n){
            if(isVowel(s[r])){
                cnt++;
            }
            if(r - l + 1 == k){
                ans = max(ans ,cnt);
                if(isVowel(s[l])){
                    cnt--;
                }
                l++;
            }
            r++;
        }

        return ans;
        
    }
};