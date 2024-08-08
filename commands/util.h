#include <string>
#include <vector>

enum CommandCode {
    ls_c,
    pwd_c,
    cd_c,
    mkdir_c,
    mv_c,
    cp_c,
    rm_c,
    echo_c,
    clear_c,
    exit_c,
    info_c,
    default_c,
};

std::vector<std::string> split_dir(const std::string& s, const std::string& d);
std::vector<std::string> move_dir(const std::vector<std::string>& path, const std::string& move_path);
std::string concat_str(const std::vector<std::string>& v, const std::string& sep);
std::string getOsName();
void helper(CommandCode code);
