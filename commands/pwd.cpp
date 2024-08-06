#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

#include "pwd.h"
#include "util.h"

std::vector<std::string> pwd_command() {
    std::string curr_dir = std::filesystem::current_path().generic_string();

    std::vector<std::string> filepath = split_dir(curr_dir, "/");
    return filepath;
}
