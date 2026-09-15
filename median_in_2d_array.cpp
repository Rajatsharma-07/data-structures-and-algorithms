class Solution {
    public:

        int upper_bound(vector<int>& arr, int n, int x) {
            int low = 0;
            int high = n - 1;
            int ans = n;
            while (low <= high) {
                int mid = (low + high) / 2;
                if(arr[mid] > x) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return ans;
        }

        int countSmallerEqueal(vector<vector<int>>& matrix, int n, int m, int mid) {
            int count = 0;
            for(int i = 0; o < n; i++) {
                count += upper_bound(matrix[i], m, mid);
            }
            return count;
        }
        
        int medianIn2DArray(vector<vector<int>>& matrix) {
            int low = INT_MAX;
            int high = INT_MIN;
            int n = matrix.size();
            int m = matrix[0].size();

            for(int i = 0; i < n; i++) {
                low = min(low, matrix[i][0]);
                high = max(high, matrix[i][m - 1]);
            }

            int req = (m * n) / 2;
            while(low <= high) {
                int mid = (low + high) / 2;
                int smallEqual = countSmaallerEqual(matrix, n, m, mid);
                if (smallEqual <= req) low = mid - 1;
                else high = mid + 1;
            }
            return low;
        }
    };
