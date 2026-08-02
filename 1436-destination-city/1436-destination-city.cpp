class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> mp;

        for(auto path : paths){
            string src = path[0];

            mp[src]= 1;
        }

        for(auto path : paths){
            string dest = path[1];

            if(mp[dest] != 1){
                return dest;
            }
        }
        return "";
    }
};