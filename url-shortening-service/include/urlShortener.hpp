#ifndef URL_SHORTENER_HPP
#define URL_SHORTENER_HPP

#include <string>
#include <unordered_map>
#include <random>

class UrlShortener {
public:
    UrlShortener();

    std::string shorten(const std::string& longUrl);
    std::string retrieve(const std::string& shortUrl);

private:
    std::unordered_map<std::string, std::string> shortToLong;
    std::unordered_map<std::string, std::string> longToShort;

    std::string generateShortCode();
    static const int CODE_LENGTH = 6;
};

#endif // URL_SHORTENER_HPP
