/*Given an integer array nums sorted in non-decreasing order, return an array of the squares of each 
number sorted in non-decreasing order.

 
Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        //initialize 3 pointers left, right and index
        //index is the pointer used to  fill the result array from the back
        int left = 0;
        int right = nums.size()-1;
        int index = n-1;
        
        //squaring every element in the array till right and left meets
        while(left <= right){
            int leftsq = nums[left]*nums[left];
            int rightsq = nums[right]*nums[right];

            /*result is the new array and index points towards the pointer  where the square is being saved*/
            if(leftsq > rightsq){
                result[index] = leftsq; 
                left ++;
            }

            else{
                result[index] = rightsq;
                right --;
            }
            index--;
        }
        return result;
    }
};

int main() {
    // 1. Create a test case
    vector<int> myNums = {-4, -1, 0, 3, 10};

    // 2. Instantiate the Solution class
    Solution sol;

    // 3. Call the function and store the result
    vector<int> finalResult = sol.sortedSquares(myNums);

    // 4. Print the result so we can see it
    cout << "Sorted Squares: [ ";
    for (int x : finalResult) {
        cout << x << " ";
    }
    cout << "]" << endl;

    return 0;
}

//time complexity - O(n)
//space complexity - O(n)