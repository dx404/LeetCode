class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size(), low = 0, high = n -1 ;  
        int maxArea = 0;  
        while (low < high) {  
            maxArea = max(maxArea, (high - low) * min(height[low], height[high]));  
            if (height[low] < height[high]) {  
                low++;  
            } else {  
                high--;  
            }  
        }  
        return maxArea;  
    }
};

