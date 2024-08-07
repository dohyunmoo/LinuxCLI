#include <iostream>
#include <string>
#include <filesystem>
#include <numeric>

#include "ls.h"
#include "util.h"

namespace fs = std::filesystem;

void ls_command (const std::vector<std::string>& path) {
    std::string path_str = concat_str(path, "/");

    try {
        for (const auto& entry : fs::directory_iterator(path_str)) {
            std::cout << entry.path().generic_string() << std::endl;
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error accessing directory: " << e.what() << std::endl;
    }
}

void ls_command (const std::vector<std::string>& path, const std::string& move_path) {
    try {
        std::vector<std::string> final_path = move_dir(path, move_path);
        std::string final_path_str = concat_str(final_path, "/");

        for (const auto& entry : fs::directory_iterator(final_path_str)) {
            std::cout << entry.path().generic_string() << std::endl;
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error accessing directory: " << e.what() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
}
