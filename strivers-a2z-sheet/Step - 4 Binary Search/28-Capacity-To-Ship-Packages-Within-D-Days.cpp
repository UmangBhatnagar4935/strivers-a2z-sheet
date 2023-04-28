
#include <bits/stdc++.h>
using namespace std;

/*
# Book Allocaton Problem 
# hai same

jaise ram ka shyam
jaise soni ka shaam jaauuu mahhhuuu

1 - pura package ke hoga aaise nahi hota hai ki main divide kar du
2 - har ek din me ek package lena hai
3 - coutinous manner - we can take particuar element 
*/

class Solution {
private: 
   bool AllocatePackage(vector<int>& arr, int daysTotal, int mid){
        int n = arr.size();
        int days = 1;
        int sum = 0;

        for(int i = 0; i<n; i++){
            if(sum + arr[i] <= mid){
                sum = sum + arr[i];
            }else{
                days++;
                if(days > daysTotal or arr[i] > mid){
                    return false;
                }
                sum = arr[i];
            }
        }
        return true;
   }
public:
    int shipWithinDays(vector<int>& arr, int days) {

     // fint the size of the array 
     int n = arr.size();
     int maxElement = INT_MIN;
     int sum = 0;

     for(int index = 0; index < n; index++){
         maxElement = max(maxElement,arr[index]);
         sum = sum + arr[index];
     }

     int start = maxElement;
     int end = sum;
     int result = -1;

     while(start <= end){
         int mid = start  + (end - start)/2;
         if(AllocatePackage(arr,days,mid)){
             result = mid;
             end = mid - 1;
         }else{
             start = mid +1;
         }
     }
     return result;
    }
};