
// LEETcode - 53. Maximum Subarray
// problem link - https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int maxisum = INT_MIN;
        int n = nums.size(); 

        for(int index = 0; index < n; index ++){
            currsum = currsum + nums[index];

            if(currsum > maxisum){
                maxisum = currsum;
            }
            if(currsum < 0){
                currsum = 0;
            }
        }
        return maxisum;
    }
};