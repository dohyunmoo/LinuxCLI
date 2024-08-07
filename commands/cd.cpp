#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <stdexcept>

#include "cd.h"
#include "util.h"

namespace fs = std::filesystem;

std::vector<std::string> cd_command(const std::vector<std::string>& curr_path, const std::string& move) {
    std::string curr_path_str = concat_str(curr_path, "/");
    std::vector<std::string> validate;
    std::vector<std::string> move_vec = split_dir(move, "/");

    if (move_vec[0].substr(0, 1) == "." || move_vec[0].substr(0, 2) == "..") {
        validate = move_dir(curr_path, move);
    } else {
        for (const auto& entry : fs::directory_iterator(curr_path_str)) {
            if (entry.is_directory()) {
                if (entry.path().filename().string() == move_vec[0]) {
                    validate = move_dir(curr_path, "./" + move);
                    break;
                }
            }
        }
    }

    if (fs::exists(concat_str(validate, "/"))) {
        return validate;
    } else {
        throw std::invalid_argument("Error accessing directory, the entered path does not exist");
    }
}
