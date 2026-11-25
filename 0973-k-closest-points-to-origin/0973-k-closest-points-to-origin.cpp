class Solution {
public:
    using piii = pair<int , pair<int, int>>;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<piii> pq;
        for(int i=0; i<points.size(); i++){
            pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], {points[i][0], points[i][1]}});

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while(pq.size() > 0){
            auto it = pq.top(); // {dis, {x , y}}
            int x = it.second.first;
            int y = it.second.second;
            res.push_back({x, y});
            pq.pop();
        }
        return res;
    }   
};