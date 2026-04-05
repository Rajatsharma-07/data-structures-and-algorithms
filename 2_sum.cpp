class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                cout << nums[i] << endl;
            }
            int low = 0;
            int high = n - 1;
    
    
            while(low < high) {
                int sum = nums[low] + nums[high];
                if (sum < target) {
                    low++;
                } else if(sum > target) {
                    high--;
                }
                else {
                    cout << "I am here" << endl;
                    cout << low << " " << high;
                    break;
                }
            }
    
            return {low, high};
        }
    };
