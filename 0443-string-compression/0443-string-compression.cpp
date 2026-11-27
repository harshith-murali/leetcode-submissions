class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0 , idx = 0; // i will explore chars while idx will point to char or freq

        int n = chars.size();

        while(i < n){
            char currChar = chars[i];
            int count = 0;
            // duplicate found
            while(i<n && chars[i] == currChar){
                count++;
                i++;
            }
            chars[idx] = currChar;
            idx++;
            if(count > 1){
                string numStr = to_string(count);
                for(char &ch : numStr){
                    chars[idx++] = ch;
                }
            }
        }
        return idx;
    }
};