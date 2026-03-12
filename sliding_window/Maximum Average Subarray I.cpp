/*
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return 
this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:

Input: nums = [5], k = 1
Output: 5.00000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double currentSum = 0, maxSum = 0;
        //Check for all edge cases
        if(n < k || k <= 0){
            return 0.0;
        }
        
        //Initial Window
        for(int i = 0; i < k; i++){
            currentSum += nums[i];
        }
        maxSum = currentSum;

        //Sliding Window
        for(int i = k; i < nums.size(); i++){
            currentSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, currentSum);
        }

        return maxSum/k;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    
    // Test Case 2 (All negative numbers)
    vector<int> nums2 = {-1};
    int k2 = 1;

    double result1 = sol.findMaxAverage(nums1, k1);
    double result2 = sol.findMaxAverage(nums2, k2);

    // Set output to show 5 decimal places
    cout << fixed << setprecision(5);
    
    cout << "Example 1 Max Average: " << result1 << " (Expected: 12.75000)" << endl;
    cout << "Example 2 Max Average: " << result2 << " (Expected: -1.00000)" << endl;

    return 0;
}