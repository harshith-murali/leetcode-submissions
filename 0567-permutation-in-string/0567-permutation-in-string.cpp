class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if(n > m){
            return false;
        }

        sort(begin(s1) , end(s1));

        for(int i=0; i<=m-n; i++){
            string substring = s2.substr(i,n); // starting index, count

            sort(begin(substring) , end(substring));

            if(s1 == substring){
                return true;
            }
        }
        return false;
    }
};