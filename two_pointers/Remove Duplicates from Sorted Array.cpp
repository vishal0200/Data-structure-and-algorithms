/*Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that 
each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number 
of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements 
beyond index k - 1 can be ignored.

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        int n = nums.size();
        int i = 0;

        for(int j = 1; j < n; j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    Solution sol;

    // 1. Prepare a sorted input vector with duplicates
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    // 2. Call the function
    // k represents the number of unique elements
    int k = sol.removeDuplicates(nums);

    // 3. Print the results
    cout << "Number of unique elements: " << k << endl;
    cout << "Modified vector: [";
    for (int idx = 0; idx < k; idx++) {
        cout << nums[idx] << (idx < k - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}

//time complexity - O(n)
//space complexity - O(1)