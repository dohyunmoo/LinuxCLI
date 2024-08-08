#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <stdexcept>

#include "mkdir.h"
#include "util.h"

namespace fs = std::filesystem;

void mkdir_command(std::vector<std::string> curr_path, std::string path) {
    std::string curr_path_str = concat_str(curr_path, "/");

    if (fs::exists(curr_path_str + path)) {
        throw std::invalid_argument("Error creating directory, the entered path already exists");
    }

    fs::create_directory(curr_path_str + "/" + path);
}

void mkdir_p_command(std::vector<std::string> curr_path, std::string path) {
    std::string curr_path_str = concat_str(curr_path, "/");

    fs::create_directories(curr_path_str + "/" + path);
}