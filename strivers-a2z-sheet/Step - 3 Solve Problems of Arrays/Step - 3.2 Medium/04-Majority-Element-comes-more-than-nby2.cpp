
#include<bits/stdc++.h>
using namespace std;

// Approach - 1
// 1 - using count the element how many times come into the array using looping 
class Solution {
public:
    int majorityElement(vector<int>& nums) {   
    
       int countMajority = nums.size()/2;
        
        for(auto num : nums){
            int count = 0;
            for(auto element : nums){
                if(element == num){
                    count++;
                }
            }
            if(count > countMajority){
                return num;
            }
        }
        return 0;
        // TLE - provide leetcode 
    }
};

// Approach 2 - we can use hashmap 

// approach 3 - we can use moree's voting algoritm 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    
      // Moore's voting algoritm 
      int n = nums.size();
      int count = 0;
      int element;

      for(int i = 0; i<n; i++){
          if(count == 0){
              count = 1;
              element = nums[i];
          }else if(element == nums[i]){
              count ++;
          }else{
              count --;
          }
      }

    int tempIncrement = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == element) 
            tempIncrement++;
    }

    if (tempIncrement > (n / 2)) 
        return element;
    else
       return -1;
    }
};
