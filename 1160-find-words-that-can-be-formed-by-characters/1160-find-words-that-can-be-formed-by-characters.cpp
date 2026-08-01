class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26,0);

        for(int i=0; i<chars.length(); i++){
            freq[chars[i]-'a']++;
        }

        int res = 0;

        for(string &word : words){
            vector<int> wordCount(26,0);

            for(char &ch : word){
                wordCount[ch - 'a']++;
            }

            bool ok = true;
            for(int i=0; i<26; i++){
                if(wordCount[i] > freq[i]){
                    ok = false;
                    break;
                }
            }
            if(ok) res += word.length();
        }


        return res;
    }
};