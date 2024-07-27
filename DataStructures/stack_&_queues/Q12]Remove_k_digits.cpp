class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char> st;
        for( char digit : num){
            while(!st.empty()  && k>0 && st.top()>digit){
                st.pop();
                k--;
            }
            st.push(digit);
        }

        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result; // Prepend the character to the result string
            st.pop();
        }

        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        result = result.substr(start);

        // If the result is empty, return "0"
        return result.empty() ? "0" : result;
    }    
    
};
//this will give memory lmit exceeded error if we are gving input string too much big. to avoid memory limit exceeded error we can use string instead of stack data structure 
// Greedy Strategy with a Stack:

// We use a stack to keep track of the digits of the smallest possible number as we iterate through the input digits.
// Steps:

// Iterate through each digit: For each digit in the input string num:
// Remove larger digits from the stack: If the current digit is smaller than the digit at the top of the stack, and if we still have digits to remove (k > 0), then pop the top of the stack. This ensures that larger digits are removed early to make space for smaller digits, thus forming a smaller number.
// Push the current digit: After removing the necessary larger digits, push the current digit onto the stack.
// Remove remaining digits: If there are still digits left to remove after processing all digits (k > 0), remove them from the end of the stack. This handles cases where we haven't removed enough digits during the iteration.
// Construct the result: Convert the stack to a string, making sure to remove any leading zeros.
// Edge Cases:

// If after all removals, the resulting number is empty, return "0".
// Ensure no leading zeros in the final result except for the number "0".