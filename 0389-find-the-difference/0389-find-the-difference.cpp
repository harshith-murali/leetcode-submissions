class Solution {
public:
    char findTheDifference(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        int s1 = 0 , s2 = 0;
        for(int i=0; i<n1; i++){
            s1 += s[i];
        }
        for(int i=0; i<n2; i++){
            s2 += t[i];
        }
        return char(abs(s1-s2));
    }
};