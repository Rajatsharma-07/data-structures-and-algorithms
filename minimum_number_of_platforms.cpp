class Solution {
    public:
        int findMinPlatform(vector<int>& arr, vector<int>& dep) {
            int n = arr.size();

            sort(arr.begin(), arr.end());
            sort(dep.begin(), dep.end());

            int i = 0, j = 0;
            int count = 0, maxCount = 0;

            while (i < n) {
                if (arr[i] <= dep[j]) {
                    count = count + 1;
                    i++;
                } else {
                    count = count - 1;
                    j = j + 1;
                }
                maxCount = max(count, maxCount);
            }

            return maxCount;
        }
    };
