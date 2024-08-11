#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <stdexcept>

#include "rm.h"
#include "util.h"

namespace fs = std::filesystem;

void rm_command(const std::vector<std::string>& curr_path, const std::string& file) {
    std::string curr_path_str = concat_str(curr_path, "/");

    if (fs::exists(curr_path_str + "/" + file)) {
        if (!fs::is_directory(curr_path_str + "/" + file)) {
            try {
                fs::remove(curr_path_str + "/" + file);
            } catch (const fs::filesystem_error& e) {
                throw std::invalid_argument(e.what());
            }
        }
    }
}

void rm_r_command(const std::vector<std::string>& curr_path, const std::string& dir) {
    std::string curr_path_str = concat_str(curr_path, "/");

    if (fs::exists(curr_path_str + "/" + dir)) {
        if (fs::is_directory(curr_path_str + "/" + dir)) {
            try {
                fs::remove(curr_path_str + "/" + dir);
            } catch (const fs::filesystem_error& e) {
                throw std::invalid_argument(e.what());
            }
        }
    }
}