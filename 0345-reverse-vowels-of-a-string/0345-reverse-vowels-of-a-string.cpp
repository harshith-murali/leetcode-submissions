class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'A' || ch == 'a' ||
               ch == 'E' || ch == 'e' ||
               ch == 'I' || ch == 'i' ||
               ch == 'O' || ch == 'o' ||
               ch == 'U' || ch == 'u';
    }
    
    string reverseVowels(string s) {
        int st = 0, e = s.length() - 1;

        while (st < e) {
            if (isVowel(s[st]) && isVowel(s[e])) {
                swap(s[st], s[e]);
                st++;
                e--;
            } 
            else if (!isVowel(s[st])) {
                st++;
            } 
            else {
                e--;
            }
        }
        return s;
    }
};