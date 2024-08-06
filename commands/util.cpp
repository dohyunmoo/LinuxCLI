#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

std::vector<std::string> split_dir(const std::string& s, const std::string& d) {
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;
    while ((end = s.find(d, start)) != std::string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(s.substr(start));
    return tokens;
}

std::vector<std::string> move_dir(const std::vector<std::string>& path, const std::string& move_path) {
    std::vector<std::string> move = split_dir(move_path, "/");

    std::vector<std::string> result;

    if (move[0] == ".." || move[0] == ".") {
        int inc = move[0] == ".." ? 1 : 0;

        for (size_t i = 0; i < path.size() - inc; i++) {
            result.push_back(path[i]);
        }
    } else {
        result.push_back(move[0]);
    }

    for (size_t i = 1; i < move.size(); i++) {
        if (move[i] == "..") {
            if (result.size() > 0) {
                result.pop_back();
            } else {
                throw std::invalid_argument("Invalid path input");
            }
        } else if (move[i] == "." || move[i] == "\0") {
            continue;
        } else {
            result.push_back(move[i]);
        }
    }

    return result;
}

std::string concat_str(const std::vector<std::string>& v, const std::string& sep) {
    std::string result = v.empty() ? "" : v[0];
    for (size_t i = 1; i < v.size(); i++) {
        result += sep + v[i];
    }
    return result;
}

std::string getOsName()
{
    #ifdef _WIN32 || _WIN64
    return "Windows";
    #else
    return "Other";
    #endif
}
