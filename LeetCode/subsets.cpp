class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<set<int>> subsets;
        subsets.insert(set<int>());
        for(int i=0; i < nums.size(); ++i){
            auto begin = subsets.begin(), end = subsets.end();
            for(auto it = begin; it != end; it++){
                set<int> new_set = *it;
                new_set.insert(nums[i]);
                subsets.insert(new_set);
            }
        }
        
        vector<vector<int>> subsets_vec;
        for(auto subset : subsets){
            vector<int> subset_vec;
            for(auto s : subset)
                subset_vec.push_back(s);
            subsets_vec.push_back(subset_vec);
        }
        
        return subsets_vec;
    }
};