#include <iostream>
#include <string>
#include <cstring>
#include <type_traits>
#include "installer.h"

void Install::Install(char* flatpath){
char cprefix[100] = "flatpak install -y ";
std::strcat(cprefix,flatpath);
std::string command(cprefix);
system(command.c_str());
}
