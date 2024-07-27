//question is not touugh. but this type of question  like they give class initially and some function and we have to implement it are need to practise and hard to understand.

class Solution {
public:

    int findGain(string &s, string substring, int points){
        int score=0;
        stack<char> stk;

        for (char c : s) {
            if (!stk.empty() && stk.top() == substring[0] && c == substring[1]) {
                stk.pop();
                score += points;
            } else {
                stk.push(c);
            }
        }
    
        // Reconstruct the remaining string after removing prioritized substrings
        string remaining;
        while (!stk.empty()) {
            remaining.push_back(stk.top());
            stk.pop();
        }
        reverse(remaining.begin(), remaining.end());
        s = remaining;
    
        return score;
    }

    int maximumGain(string s, int x, int y) {
        int total_score=0;
        if(x>=y){
            total_score+=findGain(s,"ab",x);
            total_score+=findGain(s,"ba",y);
        }else{
            total_score+=findGain(s,"ba",y);
            total_score+=findGain(s,"ab",x);
        }
        return total_score;
    }
};
//www.leetcode.com/problems/Find-elements-in-contaminated-binary-tree