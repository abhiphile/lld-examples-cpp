#include "fileSystem.hpp"
#include <iostream>

using namespace std;

int main() {
    FileStorage fs("storage");

    fs.save("hello.txt", "Hello, LLD World!");
    fs.save("data.txt", "File storage system in C++");

    cout << "Reading hello.txt: " << fs.load("hello.txt") << endl;

    auto files = fs.listFiles();
    cout << "Files in storage:" << endl;
    for (auto &file : files) cout << "- " << file << endl;

    return 0;
}
