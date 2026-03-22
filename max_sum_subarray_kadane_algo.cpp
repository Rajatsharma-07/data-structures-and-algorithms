class Solution {
    public:
        int kadanesAlgo(vector<int>& nums) {
            int sum = nums[0];
            int maxSum = sum;
            for(int i = 1; i < nums.size(); i++) {
                if (sum < 0) {
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
                maxSum = max(maxSum, sum);
            }
            return maxSum
        }
    };