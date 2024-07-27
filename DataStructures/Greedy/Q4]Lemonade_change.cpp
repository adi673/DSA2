#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) {
                    return false; // No $5 bill to give change
                }
                five--;
                ten++;
            } else if (bill == 20) {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false; // Not enough bills to give change
                }
            }
        }
        
        return true; // Successfully provided change for all bills
    }
};

int main() {
    Solution solution;
    vector<int> bills = {5, 5, 5, 10, 20};
    bool result = solution.lemonadeChange(bills);
    if (result) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}


//revise once 
//Date 14/07/2024