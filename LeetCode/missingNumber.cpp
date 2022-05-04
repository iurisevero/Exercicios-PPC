class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actual_sum = 0, real_sum = 0;
        for(int n : nums)
            actual_sum += n;
        
        int _size = nums.size();
        real_sum = (_size % 2? _size * ((_size + 1) / 2) : (_size / 2) * (_size + 1));
        return real_sum - actual_sum;
    }
};