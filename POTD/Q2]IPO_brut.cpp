class Solution {
public:

    int find(int w, vector<int>& profits, vector<int>& capital, vector<bool>& selected) {
        int max = INT_MIN;
        int max_index = -1;
        for (int i = 0; i < profits.size(); i++) {
            if (!selected[i] && profits[i] > max && capital[i] <= w) {
                max = profits[i];
                max_index = i;
            }
        }
        if (max_index != -1) {
            selected[max_index] = true; // Mark this project as selected
        }
        return max_index;
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<bool> selected(profits.size(), false); // Track selected projects
        int itr = 0;
        int profit = w;
        
        while (itr < k) {
            int index_max_prof = find(w, profits, capital, selected);
            if (index_max_prof == -1) {
                // No more projects can be selected
                break;
            }
            cout << index_max_prof << " ";
            itr++;
            profit += profits[index_max_prof];
            w = w - capital[index_max_prof] + profits[index_max_prof];
        }
        cout << endl;
        cout << profit << endl;

        return profit;
    }
};
