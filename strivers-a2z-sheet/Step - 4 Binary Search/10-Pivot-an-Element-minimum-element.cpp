#include <bits/stdc++.h>
using namespace std;

// pivot element = minimum element of the array 
// think - jo tumhe phale se aata hai 
// tum binary search se socho bas ):


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start)/2;

        while(start<end){
            if(nums[mid] < nums[mid+1]){
                start = mid + 1;
            }else if(nums[mid] > nums[mid+1]){
                end = mid;
            }
            mid = start + (end - start)/2;
        }
        return start;
    }
};