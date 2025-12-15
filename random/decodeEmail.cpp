#include <vector>
#include <iostream>
#include <string>

std::string decode(std::vector<int> message, int secretKey)
{
    // XOR the message in-place
    for (size_t i{0}; i < message.size(); ++i)
    {
        message[i] ^= secretKey;
    }

    std::string decoded;
    decoded.reserve(message.size());

    for (const int &val : message)
    {
        decoded += static_cast<char>(val);
    }

    return decoded;
}

int main(int argc, char *argv[])
{
    std::vector<int> encoded = {35, 44, 47, 36, 33, 13, 44, 36, 63, 62, 61, 44, 46, 40, 96, 36, 35, 57, 40, 33, 33, 36, 42, 40, 35, 46, 40, 99, 46, 34, 32};
    int secretKey = 77; // generic emergency squawk code

    std::string email = decode(encoded, secretKey);
    std::cout << email << std::endl;

    return 0;
}
