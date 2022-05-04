class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> points_heap;
        for(int i=0; i < points.size(); ++i)
            points_heap.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
        
        vector<vector<int>> ans;
        while(k--){
            pair<int, int> top = points_heap.top();
            points_heap.pop();
            ans.push_back(points[top.second]);
        }
        return move(ans);
    }
};