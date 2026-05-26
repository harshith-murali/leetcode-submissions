class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower = 0;
        int upper = 0;
        for(char ch : word){
            if(ch >= 'A' && ch <= 'Z'){
                upper |= (1 << (ch-'A'));
            }
            else{
                lower |= (1 << (ch-'a'));
            }
        }

        int common = lower & upper;
        int cnt = 0;
        while(common){
            cnt += (common & 1);
            common >>= 1;
        }
        return cnt;
    }
};