#include <iostream>
#include <string>

using namespace std;

string expandAroundCenter(string s, int left, int right) {
    int n = s.length();
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    // After exiting the loop, s[left+1...right-1] is the longest palindrome centered at s[left+1...right-1]
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0) return "";
    
    int start = 0, maxLength = 1;
    
    for (int i = 0; i < n; ++i) {
        // Odd length palindromes centered at s[i]
        string oddPal = expandAroundCenter(s, i, i);
        if (oddPal.length() > maxLength) {
            maxLength = oddPal.length();
            start = i - maxLength / 2;
        }
        
        // Even length palindromes centered between s[i] and s[i+1]
        string evenPal = expandAroundCenter(s, i, i + 1);
        if (evenPal.length() > maxLength) {
            maxLength = evenPal.length();
            start = i - maxLength / 2 + 1;
        }
    }
    
    return s.substr(start, maxLength);
}

int main() {
    string s1 = "babad";
    string s2 = "cbbd";
    
    cout << "Longest palindromic substring in \"" << s1 << "\" is: " << longestPalindrome(s1) << endl;  // Output: "bab" or "aba"
    cout << "Longest palindromic substring in \"" << s2 << "\" is: " << longestPalindrome(s2) << endl;  // Output: "bb"
    
    return 0;
}
