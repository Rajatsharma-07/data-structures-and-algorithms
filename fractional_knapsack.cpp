
struct Item {
    // Job Id
    int value;
    int weight;
};

class Solution {  
    public:
        static bool comparison (Item a, Item b) {
            return (double(a.value)/a.weight) > (double(b.value)/b.weight);
        }
        double knapsack(Item arr[], int w, int n) {
            sort(arr, arr + n, comparison);
            int weight = 0;
            double maxValue = 0.0;

            for (int i = 0; i < n; i++) {
                if (weight + arr[i].weight <= w) {
                    weight += arr[i].weight;
                    maxValue += double(arr[i].value);
                } else {
                    int remainingWeight = w - weight;
                    maxValue += (double(arr[i].value) / double(arr[i].weight)) * remainingWeight;
                    break;
                }
            }

            return maxValue;
        }
    };
