/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], 
nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // Ans array store the unique quadruplets
        vector<vector<int>>Ans;
        sort(nums.begin(), nums.end());//Sort the array if using 2 - pointers

        for(int i = 0; i < nums.size(); i++){
            // Duplicate check for i 
            if(i > 0 && nums[i] == nums[i - 1])continue;

            for(int j = i + 1; j < nums.size(); j++){
                // Duplicate check for j
                if(j > i + 1 && nums[j] == nums[j - 1])continue;

                //Two sum approach
                int left = j + 1, right = nums.size() - 1;

                while(left < right){
                    long long sum = (long long)nums[i] + (long long)nums[j] +
                            (long long)nums[left] + (long long)nums[right];

                    if(sum < target){
                        left ++;
                    }
                    else if(sum > target){
                        right --;
                    }
                    else{//sum == target
                        Ans.push_back({nums[i], nums[j], nums[left], 
                        nums[right]});
                        left ++, right --;

                        while(left < right && nums[left] == nums[left - 1])
                        left ++;
                        while(left < right && nums[right] == nums[right + 1])
                        right --;
                    }
                }
            }
        }
        return Ans;
    }
};

int main() {
    Solution sol;
    
    // Test Case: Find quadruplets that sum to 0
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    cout << "Input Array: {1, 0, -1, 0, -2, 2} | Target: " << target << endl;

    vector<vector<int>> result = sol.fourSum(nums, target);

    // Printing the 2D vector
    cout << "Unique Quadruplets found:" << endl;
    if (result.empty()) {
        cout << "None" << endl;
    } else {
        cout << "[" << endl;
        for (const auto& quad : result) {
            cout << "  [" << quad[0] << ", " << quad[1] << ", " << quad[2] << ", " << quad[3] << "]" << endl;
        }
        cout << "]" << endl;
    }

    return 0;
}

//time complexity - O(n^3)