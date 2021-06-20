class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1End = m - 1;
        int nums2End = n - 1;
        
        for (int i = m + n - 1; 0 <= i; --i) {
            if (nums2End < 0) {
                break;
            }
            
            if (nums1End >= 0 && nums1[nums1End] > nums2[nums2End]) {
                nums1[i] = nums1[nums1End--];
            } else {
                nums1[i] = nums2[nums2End--];
            }
        }
    }
};