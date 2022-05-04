class Solution {
public:
    int binarySearch(int begin, int end, int _size, int value, vector<int>& nums){
        int left = begin, right = end, mid;
        int left_aux = 0, right_aux = _size, mid_aux;
        while(left <= right){
            mid = left + (right-left) / 2;
            mid_aux = left_aux + (right_aux - left_aux)/2;
            
            cout << "Left: " << left << " / " << left % _size << endl;
            cout << "Mid: " << mid << " / " << mid % _size << endl;
            cout << "Right: " << right << " / " << right % _size << endl;
            
            cout << "Left A: " << left_aux << endl;
            cout << "Mid A: " << mid_aux << endl;
            cout << "Right A: " << right_aux << endl;
            
            if(nums[mid % _size] == value) return mid % _size;
            if(nums[mid % _size] < value){
                left = mid + 1;
                left_aux = mid_aux + 1;
            }
            else{
                right = mid - 1;
                right_aux = mid_aux - 1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int _size = nums.size(), rotation = 0;
        for(int i=1; i < _size; ++i){
            if(nums[i] < nums[i-1]){
                rotation = i;
                break;
            }
            if(nums[_size-i-1] > nums[_size-i]){
                rotation = _size-i;
                break;
            }
        }
        cout << "Rotation: " << rotation << endl;
        return binarySearch(rotation, _size + rotation, _size, target, nums);
    }
};