#include "FileManager.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

std::string FileManager::readFile(const std::string& path) {
    std::ifstream file(path, std::ios::binary);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open input file: " + path);
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();

    if (file.bad()) {
        throw std::runtime_error("Error while reading file: " + path);
    }

    return buffer.str();
}

void FileManager::writeFile(const std::string& path, const std::string& content) {
    std::ofstream file(path, std::ios::binary);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open output file: " + path);
    }

    file.write(content.data(), static_cast<std::streamsize>(content.size()));

    if (!file.good()) {
        throw std::runtime_error("Error while writing file: " + path);
    }
}