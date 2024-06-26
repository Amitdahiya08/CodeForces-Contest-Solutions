#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int countWays(const string& S) {
    int n = S.length();
    // If the length of S is odd, it's impossible to divide it 
    if (n % 2 != 0) {
        return 0;
    }

    int halfLength = n / 2;
    int count = 0;
    // We need to find pairs (P, R) such that P + R = S.substr(0, halfLength)
    for (int i = 0; i <=halfLength; ++i) {
        string P = S.substr(0, i);
        string R = S.substr(i+halfLength,n-(i+halfLength));
        if (P + R == S.substr(i,halfLength)) {
            ++count;
        }
    }

    return count;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        string S;
        cin >> S;

        int result = countWays(S);
        cout  << result << endl;
    }

    return 0;
}
