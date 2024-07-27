class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        
        for (string op : operations) {
            if (op == "C") {
                if (!record.empty()) {
                    record.pop();
                }
            } else if (op == "D") {
                if (!record.empty()) {
                    record.push(2 * record.top());
                }
            } else if (op == "+") {
                if (record.size() >= 2) {
                    int top1 = record.top();
                    record.pop();
                    int top2 = record.top();
                    record.push(top1);  // Push the first top back
                    record.push(top1 + top2);
                }
            } else {
                record.push(stoi(op)); //converting number inside string to int
            }
        }
        
        int sum = 0;
        while (!record.empty()) {
            sum += record.top();
            record.pop();
        }
        
        return sum;
    }
};