#include <iostream>
#include <string>
#include <filesystem>

#include "ls.h"

namespace fs = std::filesystem;

void ls_command (const std::string& path) {
    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            std::string path_string = entry.path().generic_string();
            std::cout << path_string << std::endl;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error accessing directory: " << e.what() << std::endl;
    }
}
