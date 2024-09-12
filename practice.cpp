#include <iostream>
#include <string>

std::string compressString(const std::string& str) {
    // Edge case: if the string is empty, return it directly.
    if (str.empty()) {
        return str;
    }

    // Initialize an empty result string.
    std::string compressed = "";
    int count = 1;

    // Loop through the string.
    for (size_t i = 1; i <= str.length(); ++i) {
        // Check if the current character is the same as the previous one.
        if (i < str.length() && str[i] == str[i - 1]) {
            count++;
        } else {
            // Append the character and the count to the compressed string.
            compressed += str[i - 1];
            compressed += std::to_string(count);
            count = 1;  // Reset the count for the next character.
        }
    }

    // If the compressed string is not shorter, return the original string.
    return compressed.length() < str.length() ? compressed : str;
}

int main() {
    // Example inputs and outputs
    std::string input1 = "aabcccccaaa";
    std::string input2 = "abcd";

    std::cout << "Input: " << input1 << " -> Output: " << compressString(input1) << std::endl;
    std::cout << "Input: " << input2 << " -> Output: " << compressString(input2) << std::endl;

    return 0;
}

