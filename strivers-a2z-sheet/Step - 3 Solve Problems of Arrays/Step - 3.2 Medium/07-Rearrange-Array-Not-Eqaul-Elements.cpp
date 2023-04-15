//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:

	void rearrange(int arr[], int n) {
	       
	 vector<int> positive,negetive;
	 
    for(int i=0;i<n;i++){
        if(arr[i]<0)
          negetive.push_back(arr[i]);
         else
           positive.push_back(arr[i]);
    }
        
        // two pointer alogrithm like merge two sorted array wali
        // we are using here 
          int i=0,j=0,k=0;

        // merge positve and negative element 
        while(i<negetive.size()&&j<positive.size())
        {
            arr[k++]=positive[j++];
            arr[k++]=negetive[i++];
            
        }

        // case -2 if postive element bahcahye hai 
         while(j<positive.size()){
                arr[k++]=positive[j++];
         }
         // case - 3 if negative element bachay hai
         while(i<negetive.size()){
                arr[k++]=negetive[i++];
         }        
                                     
    
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
