class Solution {
public:
    string removeStars(string s) {
        string ans;
        stack<char> st;
        for(char &ch : s){
            if(ch == '*') st.pop();
            else st.push(ch);
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans) , end(ans));
        return ans;
    }
};