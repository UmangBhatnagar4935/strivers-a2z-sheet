#include<bits/stdc++.h>
using namespace std;

// one approach - Three Pointer Algorithm used to solve this problem
// second apporach - we can use - couning element using number of the variable 

class Solution{
    public:
    void sort012(int nums[], int n){
     
     int low = 0, mid = 0, high = n-1;
     
        while(mid <= high) {
            
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            
            else if (nums[mid] == 1) {
                mid++;
            }
            
            else if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            }
        }  
    }

    // second appraoch - i know not optimize,but we will write down
    void sort012(int nums[], int n){
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i<n; i++){
            if(nums[i] == 0)
            count0++;
            if(nums[i] == 1)
            count1++;
            if(nums[i] == 2)
            count2++;
        }

        for(int i = 0; i<count0; i++){
            nums[i] = 0;
        }

        for(int i = count0; i<count0 + count1; i++){
            nums[i] = 1;
        }

        for(int i = count0+count1; i< n; i++){
            nums[i] = 2;
        }
    }   
};

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}
