#include <iostream>
#include <fstream>
#include <string>
#include "Lin_user.h"

int main() {
    User user{"Ivan N", "ivan", "qwerty12345"};
    Message message{"Hi", "ivan", "danil"};

    {
        std::ofstream file("data.dat", std::ios::binary | std::ios::out);
        if (file.is_open()) {
            file.write((const char*)(&user), sizeof(User));
            file.write((const char*)(&message), sizeof(Message));
        } else {
            std::cerr << "Unable to open file for writing." << std::endl;
            return 1;
        }
    }

    User loadedUser;
    Message loadedMessage;

    {
        std::ifstream file("data.dat", std::ios::binary);
        if (file.is_open()) {
            file.read((char*)(&loadedUser), sizeof(User));
            file.read((char*)(&loadedMessage), sizeof(Message));
        } else {
            std::cerr << "Cant open file ." << std::endl;
            return 1;
        }
    }

    return 0;
}