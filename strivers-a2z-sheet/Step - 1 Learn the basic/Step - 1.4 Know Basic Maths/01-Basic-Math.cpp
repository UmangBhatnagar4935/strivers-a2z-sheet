#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    // code stucture of the extraction of the digits
    while(n> 0){
        int lastdigit = n % 10;
        n = n / 10;
    }

    return 0;
}