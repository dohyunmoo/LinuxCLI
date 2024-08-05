#include <iostream>
#include <string>

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
    else return default_c;
}

int main()
{
    std::string command;
    while (1)
    {
        std::cin >> command;

        switch (hash(command))
        {
        case ls_c:
            ls_command(".");
            break;
        case pwd_c:
            break;
        case exit_c:
            std::cout << "System Exiting..." << std::endl;
            return 0;
        case default_c:
            std::cout << "invalid command input" << std::endl;
            break;
        default:
            std::cout << "To be implemented" << std::endl;
        }
    }
}
