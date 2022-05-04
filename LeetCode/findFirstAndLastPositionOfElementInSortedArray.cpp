class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto begin = nums.begin(), end = nums.end();
        if(!binary_search(begin, end, target))
            return {-1, -1};
        
        auto first = lower_bound(begin, end, target);
        auto last = upper_bound(begin, end, target);
        return {(int)(first-begin), (int)(last-begin) - 1};
    }
};