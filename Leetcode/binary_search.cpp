class Solution {
public:
    int lowerBound(vector<int>& input, int target) {
        int start = 0;
        int end = (int)input.size() - 1;

        while(end - start > 1) { // start will stay in the last of target
            int mid = start + (end - start)/2;

            if (input[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        while(input[start-1] == target && start-1 >= 0) {
            start--;
        }
        return start;
    };

    int upperBound(vector<int>& input, int target) {
        int start = 0;
        int end = (int)input.size() - 1;

        while(end - start > 1) { // start will stay in the last of target
            int mid = start + (end - start)/2;

            if (input[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        while(input[start + 1] == target && start + 1 < (int)input.size()) {
            start++;
        }
        return start;
    };
};
