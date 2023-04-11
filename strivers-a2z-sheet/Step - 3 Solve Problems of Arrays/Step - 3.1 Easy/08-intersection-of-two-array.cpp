#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
         set<int>s;
         sort(a, a + n);
         sort(b, b + m);
         int i=0;
         int j=0;
         while(i<n && j<m){
             
             if(a[i]==b[j]){
                s.insert(a[i]);
                 i++;
                 j++;
             }
             
             else if(a[i]>b[j])
                  j++;
                  
             else
                  i++;
         }
         // end of the day,we can return the size of the set 
         return s.size();
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}