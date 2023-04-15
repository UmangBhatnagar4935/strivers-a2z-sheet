/*
 Approach - 1 
1. traversal using for (i to n)
2. traversal using for(i = j +1 to n)
3. arr[i] + arr[j] == target 
4. return indexs(i,j)

but complexity - 0(n2)
*/


// BEST Appraoch 


// more optimize appraoch used here ):
/*

1 - create vector for <int,int>
2 - store the array element and index value in the array
3 - if array element is equal to the target 
4 - then we can return the indexes 

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int, int>> temp;

        for(int i = 0; i < nums.size(); i++){
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());

        int left = 0;
        int right = nums.size() - 1;

        while(left < right){

            int summ = temp[left].first + temp[right].first;

            if(summ == target){
                // we are returig the index of the array 
                return {temp[left].second, temp[right].second};
            }else if(summ < target){
                left++;
            }else{
                right--;
            }
        }
        return {};
    }
};