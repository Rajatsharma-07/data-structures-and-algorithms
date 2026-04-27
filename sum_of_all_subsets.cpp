class Solution {
    public:
        void findAllSubset(int index, int currSum, vector<int>& nums, vector<int>& sum) {
            if (index == nums.size()) {
                sum.push_back(currSum);
                return;
            }

            findAllSubset(index + 1, currSum + nums[index], nums, sum);
            findAllSubset(index + 1, currSum, nums, sum);
        }

        vector<int> sumOfSubset(vector<int>& nums) {
            vector<int> sum;
            findAllSubset(0, 0, nums, sum);
            sort(sum.begin(), sum.end());
            return sum;
        }
};