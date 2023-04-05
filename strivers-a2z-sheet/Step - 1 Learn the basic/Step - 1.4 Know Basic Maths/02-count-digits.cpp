
#include<bits/stdc++.h> 
using namespace std;

class Solution{
public:
    int countdigits(int N){

        int count = 0;
        while(N > 0){
            // int lastdigit = N % 10;
            count ++ ;
            N = N / 10;
        }

        return count;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.countdigits(N) << endl;
    }
    return 0; 
}