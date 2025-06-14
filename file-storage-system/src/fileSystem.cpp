#include "fileSystem.hpp"
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

FileStorage::FileStorage(const string &baseDir) : baseDir(baseDir) {
    fs::create_directories(baseDir);
}



bool FileStorage::save(const string &filename, const string &data) {
    ofstream out(baseDir + "/" + filename);
    if (!out) return false;
    out << data;
    out.close();
    return true;
}



string FileStorage::load(const string &filename) {
    ifstream in(baseDir + "/" + filename);
    if (!in) return "";
    string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    return content;
}



bool FileStorage::remove(const string &filename) {
    return fs::remove(baseDir + "/" + filename);
}



vector<string> FileStorage::listFiles() {
    vector<string> files;
    for (auto &entry : fs::directory_iterator(baseDir)) {
        if (entry.is_regular_file())
            files.push_back(entry.path().filename().string());
    }
    return files;
}

// #include <fstream> file read/write ke liye hota hai, aur #include <filesystem> file ya folder ke structure ko access/manage karne ke liye hota hai
