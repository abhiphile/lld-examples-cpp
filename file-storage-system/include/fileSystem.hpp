#pragma once
#include <string>
#include <vector>

using namespace std;

class FileStorage {
public:
    FileStorage(const string &baseDir);
    bool save(const string &filename, const string &data);
    string load(const string &filename);
    bool remove(const string &filename); // 🆕 Delete file
    vector<string> listFiles();

private:
    string baseDir;
};
