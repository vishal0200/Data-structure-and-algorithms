/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing 
all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include 
letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;

        while(left < right){
            while(left < right && !isalnum(s[left])){
                left ++;
            }

            while(left < right && !isalnum(s[right])){
                right --;
            }

            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
};

int main() {
    // 1. Create the 'specialist' (the object)
    Solution sol;

    // 2. Prepare the test data
    string test1 = "A man, a plan, a canal: Panama";
    string test2 = "race a car";

    // 3. Call the function and handle the boolean result
    // We use a ternary operator or if-else to print "True" instead of "1"
    cout << "Test 1: " << (sol.isPalindrome(test1) ? "True" : "False") << endl;
    cout << "Test 2: " << (sol.isPalindrome(test2) ? "True" : "False") << endl;

    return 0;
}