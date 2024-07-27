class Solution {
private:
    bool check(int amt, pair<int,int>& coins) {
        while (amt > 0) {
            if (amt >= 10 && coins.second > 0) {
                amt -= 10;
                coins.second--;
            } else if (amt >= 5 && coins.first > 0) {
                amt -= 5;
                coins.first--;
            } else {
                return false; // Not enough coins to make the change
            }
        }
        return true; // Successfully made the change
    }
public:
    bool lemonadeChange(vector<int>& bills) {
        pair<int,int> coins = {0, 0}; // {number of $5 bills, number of $10 bills}
        for (auto it : bills) {
            if (it == 5) {
                coins.first++;
            } else if (it == 10) {
                if (!check(5, coins)) {
                    return false; // Not enough change for $10 bill
                }
                coins.second++;
            } else if (it == 20) {
                if (!check(15, coins)) {
                    return false; // Not enough change for $20 bill
                }
            }
        }
        return true; // Successfully provided change for all bills
    }
};
//revise once 
//Date 14/07/2024