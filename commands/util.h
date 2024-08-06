#include <string>
#include <vector>

std::vector<std::string> split_dir(const std::string& s, const std::string& d);
std::vector<std::string> move_dir(const std::vector<std::string>& path, const std::string& move_path);
std::string concat_str(const std::vector<std::string>& v, const std::string& sep);
