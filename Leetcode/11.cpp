class Solution {
public:
    int maxArea(vector<int>& height) { //Time Limit Exceeded
        if (height.size() < 2) {
            return 0;
        }
        int ans = 0;
        for(int i = 0; i < height.size() - 1; ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                int lower = min(height[i], height[j]);
                int width = j - i;
                ans = max(width * lower, ans);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        
        while(left < right) {
            ans = max(ans, min(height[right], height[left]) * (right - left));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return ans;
    }
};