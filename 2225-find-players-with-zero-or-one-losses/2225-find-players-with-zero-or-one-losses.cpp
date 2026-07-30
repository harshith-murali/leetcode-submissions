class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mp; // player , losses

        for(auto it : matches){
            int loser = it[1];

            mp[loser]++;
        }
        vector<int> notLost;
        vector<int> lostOnce;

        for(int i=0; i<matches.size(); i++){
            int winner = matches[i][0];
            int loser = matches[i][1];

            if(mp.find(winner) == mp.end()){
                notLost.push_back(winner);
                mp[winner] = 2;
            }

            if(mp[loser] == 1){
                lostOnce.push_back(loser);
            }
        }
        sort(begin(notLost) , end(notLost));
        sort(begin(lostOnce) , end(lostOnce));
        return {notLost, lostOnce};
    }
};