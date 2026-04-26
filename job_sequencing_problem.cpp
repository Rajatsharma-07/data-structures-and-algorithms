
struct Job {
    // Job Id
    int id; 
    // Deadline of job
    int dead;
    // Profit if job is completed before or on the deadline 
    int profit; 
};

class Solution {  
    public:
        static bool comparison (Job a, Job b) {
            return a.profit > b.profit;
        }
        pair <int, int> jobSequencing(Job arr[], int n) {
            sort(arr, arr + n, comparison);
            int count = 0;
            int maxProfit = 0;
            int maxDeadline = 0;

            for (int i = 0; i < n; i++) {
                maxDeadline = max(maxDeadline, arr[i].dead);
            }

            vector<int> hash(maxDeadline + 1, -1);

            for (int i = 0; i < n; i++) {
                for (int j = arr[i].dead; j > 0; j++) {
                    if (hash[j] == -1) {
                        count = count + 1;
                        hash[j] = arr[i].id;
                        maxProfit = maxProfit + arr[i].profit;
                        break;
                    }
                }
            }

            return {count, maxProfit};
        }
    };
