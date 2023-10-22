#include <iostream>
#include <string>

std::string countAndSay(int n) {
    if (n <= 0) {
        return "";
    } else if (n == 1) {
        return "1";
    }

    std::string result = "1";
    for (int i = 2; i <= n; i++) {
        std::string current;
        char digit = result[0];
        int count = 1;

        for (int j = 1; j < result.size(); j++) {
            if (result[j] == digit) {
                count++;
            } else {
                current += std::to_string(count) + digit;
                digit = result[j];
                count = 1;
            }
        }

        current += std::to_string(count) + digit;
        result = current;
    }

    return result;
}

int main() {
    int n = 5; // Change n to generate a different term in the sequence.
    std::string result = countAndSay(n);
    std::cout << "Term " << n << " in the Count and Say sequence: " << result << std::endl;

    return 0;
}
