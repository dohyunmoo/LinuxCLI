#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <stdexcept>

#include "cp.h"
#include "util.h"

namespace fs = std::filesystem;

void cp_command(std::vector<std::string> curr_path, std::string copy_path_str, std::string target_path_str) {
    std::string curr_path_str = concat_str(curr_path, "/");
    std::string copy_path_str_all = curr_path_str + "/" + copy_path_str;

    if (!fs::exists(copy_path_str_all)) {
        throw std::invalid_argument("The file you are trying to copy from does not exist");
    }

    std::string target_path_str_all = curr_path_str + "/" + target_path_str;

    try {
        fs::copy(copy_path_str_all, target_path_str_all);
    } catch (const fs::filesystem_error& e) {
        throw std::invalid_argument(e.what());
    }
}

void cp_r_command(std::vector<std::string> curr_path, std::string copy_path_str, std::string target_path_str) {
    std::string curr_path_str = concat_str(curr_path, "/");
    std::string copy_path_str_all = curr_path_str + "/" + copy_path_str;

    if (!fs::exists(copy_path_str_all)) {
        throw std::invalid_argument("The file you are trying to copy from does not exist");
    }

    std::string target_path_str_all = curr_path_str + "/" + target_path_str;

    try {
        fs::copy(copy_path_str_all, target_path_str_all, fs::copy_options::recursive);
    } catch (const fs::filesystem_error& e) {
        throw std::invalid_argument(e.what());
    }
}
