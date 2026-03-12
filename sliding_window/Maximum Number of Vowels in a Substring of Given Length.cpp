/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s 
with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char>vowels = {'a','e','i','o','u'};
        int count = 0, maxCount = 0;
        
        // Count vowels in first window of size k
        for( int i = 0; i < k; i++){
            if(vowels.count (s[i])) count ++;
        }
        maxCount = count;

        // Slide the window
        for( int i = k; i < s.length(); i++){
            if(vowels.count (s[i - k])) count --;// remove leftmost char
            if(vowels.count (s[i])) count ++;// add new rightmost char
            maxCount = max(count , maxCount);
        }
        return maxCount;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "abciiidef";
    int k1 = 3;
    
    // Test Case 2
    string s2 = "leetcode";
    int k2 = 3;

    cout << "Test Case 1: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "Result: " << sol.maxVowels(s1, k1) << " (Expected: 3)" << endl;

    cout << "\nTest Case 2: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "Result: " << sol.maxVowels(s2, k2) << " (Expected: 2)" << endl;

    return 0;
}

//time complexity - O(n)
//space complexity - O(1)