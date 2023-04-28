#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // you are array contain only one element then you can return single element 
        if(nums.size()==1){
            return nums[0];
        }

        int start = 0;
        int end = nums.size()-2;

        while(start <= end){
            int mid = (start + end)/2;
            if(nums[mid] == nums[mid^1]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return nums[start];
    }
};