#include <iostream>
#include <vector>

std::string multiplyStrings(std::string num1, std::string num2) {
    int m = num1.size();
    int n = num2.size();
    std::vector<int> result(m + n, 0);

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    // Convert the result vector to a string
    std::string multiplicationResult;
    for (int digit : result) {
        if (!(multiplicationResult.empty() && digit == 0)) {
            multiplicationResult.push_back(digit + '0');
        }
    }

    return multiplicationResult.empty() ? "0" : multiplicationResult;
}

int main() {
    std::string num1 = "123";
    std::string num2 = "456";

    std::string result = multiplyStrings(num1, num2);
    std::cout << "Multiplication result: " << result << std::endl;

    return 0;
}
