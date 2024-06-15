#include<bits/stdc++.h>
using namespace std;

// Function to check if a string represents a binary number
bool isBinary(string &s) {
    for (char c : s) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}

int main() {
    // Create a map to store binary numbers and their string representations
    map<int, string> binaryMap;

    // Loop through numbers from 1 to 100,001
    for (int i = 1; i <= 100001; ++i) {
        std::string numberStr = std::to_string(i);
        if (isBinary(numberStr)) {
            binaryMap[i] = numberStr;
        }
    }

    // Optionally, print the map to verify (can be commented out)
    for (const auto& pair : binaryMap) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    return 0;
}
