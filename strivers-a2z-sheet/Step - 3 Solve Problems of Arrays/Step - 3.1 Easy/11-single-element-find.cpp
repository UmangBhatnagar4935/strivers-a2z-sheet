#include <bits/stdc++.h>

using namespace std;


class Solution{
public:	
	int search(int A[], int N){
	    //code
	    
	    // Appraoch - 2 
	    // step -1 create hashmap using maximum element of the array
	    // step -2 store the counting of the array element in the hashamp
	    // step -3 if hashmap contain 1 value for any element return the element
	   // because that's we want single element 
	   // appears one only 
	   
	    unordered_map<int,int>m;
	    
	    for(int i=0; i<N; i++){
	        m[A[i]]++;
	    }
	    
	    for(int i=0; i<N; i++){
	        if(m[A[i]]==1){
	            return A[i];
	        }
	    }
	    
	    return -1;
	}
};


int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}
