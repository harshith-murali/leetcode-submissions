class Solution {
public:
    int numberOfSpecialChars(string word) {
       vector<int> upper(26,0) , lower(26,0);
       for(char ch : word){
        if(ch >= 'A' && ch <= 'Z'){
            upper[ch - 'A'] = ch;
        }else{
            lower[ch-'a'] = ch;
        }
       }
       int cnt = 0;
       for(int i=0; i<26; i++){
        if(upper[i] && lower[i]){
            cnt++;
        }
       }
       return cnt;
    }
};