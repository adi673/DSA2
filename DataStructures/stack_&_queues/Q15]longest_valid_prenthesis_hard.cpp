class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Initialize the stack with a base index
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            cout<<"i val is : "<<i<<endl;
            if (s[i] == '(') {
                cout<<"Pusing i as : "<<i<<endl;
                st.push(i);
            } else {
                cout<<"popping i as : "<<st.top()<<endl;
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    cout<<" : "<<st.top()<<endl;
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }

        return maxLength;
    }
};

//you have to practise it  again and again 
// Explanation:
// Initialization:

// Initialize the stack with -1 to handle the base index case.
// Iteration:

// Iterate through each character in the string.
// If the character is '(', push its index onto the stack.
// If the character is ')', pop the stack.
// After popping, if the stack is empty, push the current index to handle the base for the next valid substring.
// If the stack is not empty, calculate the length of the current valid substring by subtracting the current index from the top index of the stack.
// Result:

// The maximum length of valid parentheses is tracked and updated during the iteration.
// This approach ensures that the indices are managed correctly, providing an accurate length of the longest valid parentheses substring.