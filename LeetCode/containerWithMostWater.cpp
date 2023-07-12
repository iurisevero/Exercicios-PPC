class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int _size = height.size();
        
        // end - i
        
        for(int i=0, j=_size-1; i < _size, j >=0;){
            int actualArea = (j-i) * min(height[i], height[j]);
            if(maxArea < actualArea)
                maxArea = actualArea;
            
            if(i > j) break;
            
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxArea;
    }
};

// h[0] h[9] == Area = 7
// h[1] h[9] == Area = 56
// h[1] h[8]...