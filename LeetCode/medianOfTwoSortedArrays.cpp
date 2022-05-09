// 35ms 90.2MB
class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        vector<int> nums;
        int pos1 = 0, pos2 = 0, size1 = nums1.size(), size2 = nums2.size();
        while(pos1 < size1 && pos2 < size2){
            if(nums1[pos1] < nums2[pos2]){
                nums.push_back(nums1[pos1]);
                pos1++;
            } else{
                nums.push_back(nums2[pos2]);
                pos2++;
            }
        }
        
        while(pos1 < size1){
            nums.push_back(nums1[pos1]);
            pos1++;
        }
        
        while(pos2 < size2){
            nums.push_back(nums2[pos2]);
            pos2++;
        }
        
        return nums;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums = merge(nums1, nums2);        
        int _size = nums.size();
               
        if(_size % 2){
            return (double)nums[_size / 2];
        }else{
            return ((double)(nums[_size / 2]) + nums[(_size / 2) - 1]) / 2.0;
        }
    }
};