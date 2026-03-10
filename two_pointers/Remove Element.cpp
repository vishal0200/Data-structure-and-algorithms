/*Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The order of the elements may be changed. Then return the number of elements in nums which are not 
equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need 
to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal 
to val. The remaining elements of nums are not important as well as the size of nums.

Return k.

Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int j = 0; j < nums.size(); ++j){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main() {
    vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    int valToRemove = 2; 

    Solution sol;

    // Pass both arguments. 
    // Store the return value in an 'int', not a 'vector'.
    int newLength = sol.removeElement(nums, valToRemove);

    cout << "New length of array: " << newLength << endl;
    cout << "Modified Array (first " << newLength << " elements): ";
    
    // In this specific problem, only the first 'newLength' elements matter
    for(int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

//time complexity - O(n)
//space complexity - O(1)