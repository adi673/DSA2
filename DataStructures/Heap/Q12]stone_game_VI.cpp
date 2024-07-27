class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    int n = aliceValues.size();
    // Priority queue to store stones with their combined value, Alice's value, and Bob's value
    priority_queue<pair<int, int>> pq;

    // Populate the priority queue
    for (int i = 0; i < n; ++i) {
        pq.emplace(aliceValues[i] + bobValues[i], i);
    }

    int aliceScore = 0, bobScore = 0;
    bool aliceTurn = true;

    // Simulate the game
    while (!pq.empty()) {
        auto [combinedValue, i] = pq.top();
        pq.pop();
        
        if (aliceTurn) {
            aliceScore += aliceValues[i];
        } else {
            bobScore += bobValues[i];
        }

        aliceTurn = !aliceTurn; // Switch turn
    }

    // Determine the result
    if (aliceScore > bobScore) {
        return 1;
    } else if (bobScore > aliceScore) {
        return -1;
    } else {
        return 0;
    }
    }
};

//didn't got the above  logic why to pick max combined value stone in each turn and not the max value stone for particular player
//revise 2x
//my logic for picking particular stone is as follows:

//see mere pass 2 options hai 1 to mai hamesha mere list mai se max uthaunga and 2nd option is mai dono ke particular index mai jo values hai unake sum ka max uthau. second way increases your chances to win kyonki agar mai mera max uthau and kisi aur index pe mere max se bhi jyada usake apss max ki value ho and vo jeet jaye. ye avoid karne ke liye mai amx sum uthaunga. test case 2 is best example of it


//following approach is wrong the reason is written above
// int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
//     int n = aliceValues.size();
    
//     // Priority queues for Alice's and Bob's values
//     priority_queue<pair<int, int>> aliceHeap; // {value, index}
//     priority_queue<pair<int, int>> bobHeap;   // {value, index}
    
//     // Populate the priority queues with values and indices
//     for (int i = 0; i < n; ++i) {
//         aliceHeap.push({aliceValues[i], i});
//         bobHeap.push({bobValues[i], i});
//     }
    
//     int aliceScore = 0, bobScore = 0;
//     bool aliceTurn = true;
    
//     // Simulate the game
//     while (!aliceHeap.empty() || !bobHeap.empty()) {
//         if (aliceTurn) {
//             // Alice's turn: pick the stone with max value from aliceHeap
//             if (!aliceHeap.empty()) {
//                 auto [value, index] = aliceHeap.top();
//                 aliceHeap.pop();
//                 aliceScore += aliceValues[index];
//             }
//         } else {
//             // Bob's turn: pick the stone with max value from bobHeap
//             if (!bobHeap.empty()) {
//                 auto [value, index] = bobHeap.top();
//                 bobHeap.pop();
//                 bobScore += bobValues[index];
//             }
//         }
        
//         aliceTurn = !aliceTurn; // Switch turn
//     }
    
//     // Determine the result
//     if (aliceScore > bobScore) {
//         return 1; // Alice wins
//     } else if (bobScore > aliceScore) {
//         return -1; // Bob wins
//     } else {
//         return 0; // Draw
//     }
// }