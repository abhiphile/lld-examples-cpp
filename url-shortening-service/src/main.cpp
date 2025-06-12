#include <iostream>
#include "urlShortener.hpp"

int main() {
    UrlShortener service;

    std::string longUrl = "https://example.com/very/long/url";
    std::string shortCode = service.shorten(longUrl);
    std::cout << "Shortened URL: " << shortCode << std::endl;

    std::string original = service.retrieve(shortCode);
    std::cout << "Retrieved original URL: " << original << std::endl;

    return 0;
}
