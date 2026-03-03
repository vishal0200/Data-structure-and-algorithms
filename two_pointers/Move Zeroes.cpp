/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of 
the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nonZeroIndex = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[nonZeroIndex] = nums[i];
                nonZeroIndex ++;
            }
        }

        for(int i = nonZeroIndex; i < n; i++){
            nums[i] = 0;
        }
    }
};

int main() {
    // 1. Create a test case
    vector<int> nums = {0, 1, 0, 3, 12};

    // 2. Instantiate the class
    Solution sol;

    // 3. Call the function (No return value, it modifies 'nums' directly)
    sol.moveZeroes(nums);

    // 4. Print the result using a for-each loop (modern C++)
    cout << "Modified Array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

//time complexity - O(n)
//space complexity - O(1)

/*
There can be a one pass solution to the given problem

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int nonZeroIndex = 0;

       for(int i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            // Swap the current non-zero element with the 
            // element at the current 'zero' pointer
            swap(nums[nonZeroIndex], nums[i]);
            nonZeroIndex ++;
        }
       }
    }
};

The time complexity of both the solution is same but still i'd prefer one pass solution for the given
problem since it can solve the complete problem with a few swaps rather then traversing the whole 
array (in the case of a thousand elements, with only 3-4 non zero elements in it)
*/