class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        
        // Total sum of array
        for (int x : nums) {
            total += x;
        }

        int leftSum = 0;

        // Traverse and check pivot
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == total - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
};