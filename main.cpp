#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "commands/ls.h"
#include "commands/pwd.h"
#include "commands/cd.h"
#include "commands/mkdir.h"
#include "commands/cp.h"
#include "commands/rm.h"

#include "commands/util.h"

CommandCode hash (const std::string& commandString) {
    if (commandString == "ls") return ls_c;
    if (commandString == "pwd") return pwd_c;
    if (commandString == "cd") return cd_c;
    if (commandString == "mkdir") return mkdir_c;
    if (commandString == "mv") return mv_c;
    if (commandString == "cp") return cp_c;
    if (commandString == "rm") return rm_c;
    if (commandString == "echo") return echo_c;
    if (commandString == "clear") return clear_c;
    if (commandString == "exit") return exit_c;
    if (commandString == "info") return info_c;
    else return default_c;
}

void print_dir(const std::vector<std::string>& filepath) {
    for (size_t i = 0; i < filepath.size(); i++) {
        if (i == 0) {
            std::cout << filepath[i];
        } else {
            std::cout << '/' << filepath[i];
        }
    }
}

int main(int argc, char* argv[])
{
    std::vector<std::string> filepath = pwd_command();
    std::string user = argc > 1 ? argv[1] : "root";

    bool running = true;
    while (running)
    {
        std::string command;
        std::vector<std::string> args;

        std::cout << user << '@' << "dohyunmoo -> ";
        print_dir(filepath);
        std::cout << "$ ";

        std::getline(std::cin, command);

        if (!command.empty()) {
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
                        std::string errmsg = "Too many arguments for command ls";
                        throw std::invalid_argument(errmsg);
                    } else if (args.size() > 1) {
                        ls_command(filepath, args[1]);
                    } else {
                        ls_command(filepath);
                    }
                    break;
                case pwd_c:
                    print_dir(filepath);
                    std::cout << std::endl;
                    break;
                case cd_c:
                    if (args.size() > 2) {
                        std::string errmsg = "Invalid number of arguments for command cd";
                        throw std::invalid_argument(errmsg);
                    } else if (args.size() == 2) {
                        std::vector<std::string> temp = cd_command(filepath, args[1]);
                        filepath.clear();
                        for (std::string temp_f : temp) {
                            filepath.push_back(temp_f);
                        }
                    }
                    break;
                case mkdir_c:
                    if (args.size() > 3 || args.size() < 2) {
                        std::string errmsg = "Invalid number of arguments for command mkdir";
                        throw std::invalid_argument(errmsg);
                    } else if (args.size() == 3 && args[1] == "-p") {
                        mkdir_p_command(filepath, args[2]);
                    } else {
                        mkdir_command(filepath, args[1]);
                    }
                    break;
                case cp_c:
                    if (args.size() > 4 || args.size() < 3) {
                        std::string errmsg = "Invalid number of arguments for command cp";
                        throw std::invalid_argument(errmsg);
                    } else if (args.size() == 4 && args[1] == "-r") {
                        cp_r_command(filepath, args[2], args[3]);
                    } else {
                        cp_command(filepath, args[1], args[2]);
                    }
                    break;
                case rm_c:
                    if (args.size() > 3 || args.size() < 2) {
                        std::string errmsg = "Invalid number of arguments for command rm";
                        throw std::invalid_argument(errmsg);
                    } else if (args.size() == 3 && (args[1] == "-r" || args[1] == "-rf")) {
                        rm_r_command(filepath, args[2]);
                    } else {
                        rm_command(filepath, args[1]);
                    }
                    break;
                case echo_c:
                    if (args.size() != 2) {
                        std::string errmsg = "Invalid number of arguments for command echo";
                        throw std::invalid_argument(errmsg);
                    } else {
                        std::cout << args[1] << std::endl;
                    }
                    break;
                case clear_c:
                    if (args.size() > 1) {
                        std::string errmsg = "Invalid number of arguments for command clear";
                        throw std::invalid_argument(errmsg);
                    } else {
                        if (getOsName() == "Windows") {
                            system("cls");
                        } else {
                            std::cout << "\033[2J";
                        }
                    }
                break;
                case exit_c:
                    std::cout << "System Exiting..." << std::endl;
                    running = false;
                    break;
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

    std::cout << "developed by dohyunmoo @ https://github.com/dohyunmoo/LinuxCLI with C++" << __cplusplus << std::endl;
    return 0;
}
