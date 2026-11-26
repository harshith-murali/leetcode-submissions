class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        string res (n1 + n2 , ' ');
        int i = 0 , j = 0;
        int k = 0;
        while(i < n1 && j < n2){
            res[k++] = word1[i++];
            res[k++] = word2[j++];
        }
        while(i < n1){
            res[k++] = word1[i++];
        }
        while(j < n2){
            res[k++] = word2[j++];
        }
        return res;
    }
};