class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'A' || 
           ch == 'e' || ch == 'E' || 
           ch == 'i' || ch == 'I' || 
           ch == 'o' || ch == 'O' || 
           ch == 'u' || ch == 'U';
    }
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0 , j = n - 1;
        while(i < j){
            if(!isVowel(s[i])){
                i++;
            }else if(!isVowel(s[j])){
                j--;
            }else{
                swap(s[i++] , s[j--]);
            }
        }
        return s;
    }
};