/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two
endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the
most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, 
the max area of water (blue section) the container can contain is 49.

Example 2:

Input: height = [1,1]
Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, maxArea = 0;

        while(left < right){
            int h = min(height[left], height[right]);
            int w = right - left;
            maxArea = max(maxArea, h * w);

            // Move the pointer pointing to the smaller height
            if(height[left] < height[right]){
                left++;
            }

            else{
                right--;
            }
        }
        return maxArea;
    }
};

int main() {
    // 1. Define the input (Heights of the vertical lines)
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // 2. Create an instance of the class
    Solution sol;

    // 3. Call the function and store the result
    int result = sol.maxArea(heights);

    // 4. Print the output
    cout << "The maximum area of water the container can contain is: " << result << endl;

    return 0;
}

//time complexity - O(n)
//space complexity - O(1)