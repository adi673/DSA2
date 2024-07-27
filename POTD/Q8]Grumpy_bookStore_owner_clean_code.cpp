class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int total_satisfied = 0;
        int extra_satisfied = 0;
        int max_extra_satisfied = 0;

        // Calculate the total satisfied customers without grumpy interval
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0) {
                total_satisfied += customers[i];
            }
        }

        // Calculate extra satisfied customers in the initial window
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                extra_satisfied += customers[i];
            }
        }

        max_extra_satisfied = extra_satisfied;

        // Slide the window from start to end of the array
        for (int i = minutes; i < customers.size(); ++i) {
            if (grumpy[i] == 1) {
                extra_satisfied += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                extra_satisfied -= customers[i - minutes];
            }
            max_extra_satisfied = std::max(max_extra_satisfied, extra_satisfied);
        }

        return total_satisfied + max_extra_satisfied;
    }
};