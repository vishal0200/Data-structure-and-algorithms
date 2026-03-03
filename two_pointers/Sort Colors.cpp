/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
       int left = 0;
       int right = nums.size() - 1;
       int mid = 0;

       while(mid <= right){
        if(nums[mid] == 0){
            swap(nums[mid],nums[left]);
            left++;
            mid++;
        }

        else if(nums[mid] == 1){
            mid++;
        }

        else{ //nums[mid] == 2
            swap(nums[mid],nums[right]);
            right--;
        }
       }
    }
};

int main(){
    // 1. Create a test case
    vector<int> nums{2, 0, 2, 1, 1, 0};

    // 2. Instantiate the class
    Solution sol;

    // 3. Call the function (No return value, it modifies 'nums' directly)
    sol.sortColors(nums);

    // 4. Print the result using a for-each loop (modern C++)
    cout << "Modifies Array : ";
    for(int i : nums){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

//time complexity - O(n)
//space complexity - O(1)

/*This question specifically focuses on how to handle three different pointers to get to the 
solution*/