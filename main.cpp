#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "commands/ls.h"

enum CommandCode {
    ls_c,
    pwd_c,
    cd_c,
    mkdir_c,
    mv_c,
    cp_c,
    rm_c,
    echo_c,
    exit_c,
    info_c,
    default_c,
};

CommandCode hash (const std::string& commandString) {
    if (commandString == "ls") return ls_c;
    if (commandString == "pwd") return pwd_c;
    if (commandString == "cd") return cd_c;
    if (commandString == "mkdir") return mkdir_c;
    if (commandString == "mv") return mv_c;
    if (commandString == "cp") return cp_c;
    if (commandString == "rm") return rm_c;
    if (commandString == "echo") return echo_c;
    if (commandString == "exit") return exit_c;
    if (commandString == "info") return info_c;
    else return default_c;
}

int main()
{
    while (1)
    {
        std::string command;
        std::vector<std::string> args;

        std::cout << "$ ";
        std::getline(std::cin, command);

        std::istringstream iss(command);
        std::string token;

        while (iss >> token) {
            args.push_back(token);
        }

        CommandCode code = hash(args[0]);

        try {
            switch (code)
            {
            case ls_c:
                if (args.size() > 2) {
                    // std::string errmsg = std::format("too many arguments for command {}", args[0]);
                    std::string errmsg = "too many arguments for command ls";
                    throw std::invalid_argument(errmsg);
                }
                ls_command(args.size() > 1 ? args[1] : ".");
                break;
            case pwd_c:
                break;
            case exit_c:
                std::cout << "System Exiting..." << std::endl;
                return 0;
            case info_c:
                std::cout << "developed by dohyunmoo @ https://github.com/dohyunmoo/LinuxCLI with C++" << __cplusplus << std::endl;
                break;
            case default_c:
                std::cout << "invalid command input" << std::endl;
                break;
            default:
                std::cout << "To be implemented" << std::endl;
                break;
            }

        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    }
}
