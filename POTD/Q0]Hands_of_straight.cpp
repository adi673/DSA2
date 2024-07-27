class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->second > 0) {
                int current = it->first;
                int freq = it->second;

                for (int i = 0; i < groupSize; ++i) {
                    if (count[current + i] < freq) return false;
                    count[current + i] -= freq;
                }
            }
        }

        return true;
    }
};
//chatgpt gave. 
//this question can be solved using map and priority queue