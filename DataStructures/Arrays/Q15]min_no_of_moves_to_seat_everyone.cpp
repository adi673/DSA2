class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    // Sort both arrays
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    
    int totalMoves = 0;
    int n = seats.size();
    
    // Match each student to a seat
    for (int i = 0; i < n; ++i) {
        totalMoves += abs(students[i] - seats[i]);
    }
    
    return totalMoves;
    }
};
//www.letcode.com/problems/minimum-number-of-moves-to-seat-everyone/