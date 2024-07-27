class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
    int maxLength = 0;
    int left = 0;
    
    for (int right = 0; right < s.length(); ++right) {
        char currentChar = s[right];
        
        if (charMap.find(currentChar) != charMap.end()) {
            // Move left pointer to the right of the last occurrence of currentChar
            left = max(left, charMap[currentChar] + 1);
        }
        
        // Update the last seen index of the current character
        charMap[currentChar] = right;
        
        // Update maximum length of substring without repeating characters
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
    }
};