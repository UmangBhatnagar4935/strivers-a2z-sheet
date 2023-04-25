#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
         int start = 0;
         int end = n - 1;
         
         int mid  = start + (end- start)/2;
         
         while(start<=end){
             if(arr[mid] == k){
                 return mid;
             }else if(arr[mid] < k ){
                 end = mid - 1;
             }else{
                 start = mid + 1;
             }
             // we can update middle index,because every itreation we are updating the start and end index value 
             mid = start + (end - start)/2;
         }
         return -1;
    }
};

// TC - o(logN)