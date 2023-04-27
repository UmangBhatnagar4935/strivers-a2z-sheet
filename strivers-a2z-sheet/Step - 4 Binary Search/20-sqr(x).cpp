#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
         int start = 0;
         int end = x;
         long long int mid = start + (end - start)/2;
         int result;
         while(start<=end){
             long long int value = mid * mid;
             if(value == x){
                 return mid;
             }else if(value < x){
                 // it can be valid answer, we will store smaller value 
                 result = mid;
                 start = mid + 1;
             }else{
                 end = mid -1;
             }
             mid = start + (end - start)/2;
         }
         return result;
    }
};