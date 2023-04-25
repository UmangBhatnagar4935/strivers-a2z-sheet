// Find Target Indices After Sorting Array - Leetcode Questons 

#include <bits/stdc++.h>
using namespace std;


// bruth force --> optimial approach 
// 1- sort the array and apply linear search to store the element 
// 2- sort the array and apply binary search to store the element 

// - but before gonna to solve this problems
// - understand code of the binary search recrusivly using Dry Run 


class Solution {
public:
    vector <int> ans;   //to store answers
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());     //sorting arrays initially
        int start=0, end=nums.size()-1;
        binary(nums, start, end, target);   //calling binary search on whole array 
        return ans;
    }
    
    void binary(vector <int> nums, int start, int end, int target){
        if(start>end)       //if array can't be divided into subarrays anymore
            return;
        
        int mid = start + (end-start)/2;        //declaring mid element

        if(nums[mid] == target){                //when target is found, push it into ans and call binary on each halved subarrays
            binary(nums, start, mid-1, target); // go the left side
            ans.push_back(mid);
            binary(nums, mid+1, end, target);   // go the right side  
        }
        else if(nums[mid] > target)               //calling binary on lower half of array
            binary(nums, start, mid-1, target);
        else if(nums[mid] < target)                                  //calling binary on upper half of array
            binary(nums, mid+1, end, target);
    }
};