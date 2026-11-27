class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        int n = s.length();
        string res = "";

        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                int num = 0;
                while(i < n && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                numStack.push(num);
                i--;
            }else if(islower(s[i]) || s[i] == '['){
                strStack.push(string(1, s[i]));
            }else{
                string stackTop = "";
                while(strStack.top() != "["){
                    stackTop = strStack.top() + stackTop;
                    strStack.pop();
                }
                // pop the '[' also
                strStack.pop();
                
                int freq = numStack.top();
                numStack.pop();

                string curr = "";
                for(int i=0; i<freq; i++){
                    curr += stackTop;
                }
                strStack.push(curr);
            }
            
        }

        while (!strStack.empty()) {
            res = strStack.top() + res;
            strStack.pop();
        }
        return res;
    }
};