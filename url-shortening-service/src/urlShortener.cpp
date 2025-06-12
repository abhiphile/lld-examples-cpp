#include "urlShortener.hpp"

UrlShortener::UrlShortener() {}

std::string UrlShortener::shorten(const std::string& longUrl) {
    if (longToShort.find(longUrl) != longToShort.end()) {
        return longToShort[longUrl];
    }

    std::string code;
    do {
        code = generateShortCode();
    } while (shortToLong.find(code) != shortToLong.end());

    shortToLong[code] = longUrl;
    longToShort[longUrl] = code;

    return code;
}

std::string UrlShortener::retrieve(const std::string& shortUrl) {
    if (shortToLong.find(shortUrl) != shortToLong.end()) {
        return shortToLong[shortUrl];
    }
    return "";
}

std::string UrlShortener::generateShortCode() {
    static const char charset[] =
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    static std::mt19937 rng(std::random_device{}());
    static std::uniform_int_distribution<> dist(0, sizeof(charset) - 2);

    std::string code;
    for (int i = 0; i < CODE_LENGTH; ++i) {
        code += charset[dist(rng)];
    }
    return code;
}

// std::string UrlShortener::generateShortCode() {
//     const std::string charset = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     std::string code;

//     for (int i = 0; i < CODE_LENGTH; ++i) {
//         int idx = rand() % charset.size();  // simpler, but not thread-safe or high-quality
//         code += charset[idx];
//     }

//     return code;
// }
