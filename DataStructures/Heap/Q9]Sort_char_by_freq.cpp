class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count the frequency of each character
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        // Step 2: Use a max-heap to store characters based on their frequencies
        priority_queue<pair<int, char>> maxHeap;
        for (auto& entry : freqMap) {
            maxHeap.push({entry.second, entry.first});
        }

        // Step 3: Extract characters from the heap and build the result string
        string result;
        while (!maxHeap.empty()) {
            int freq = maxHeap.top().first;
            char c = maxHeap.top().second;
            maxHeap.pop();
            result.append(freq, c); //imp string function
        }

        return result;
    }
};
// Time complexity: O(N + NlogN) = O(NlogN), where N is the length of the input string s.

// Space complexity: O(N), where N is the length of the input string s. The space complexity is for the unordered_map and the priority_queue.

// Approach 2: Using a Bucket Sort do it later

//result.append(freq, c); //imp string function