#include <iostream>
#include "Headers/Tables.hpp"
#include "Headers/DataKeeper.hpp"
#include "Headers/Tools.hpp"
#include "Headers/Interface.hpp"
int main(int argc, const char * argv[]) {
    bool flag = 1;
    Interface interface;
    while(flag){
        flag = interface.Command_getter();
    }
//    Interface interf;
//    interf.Command_getter();
//    interf.Command_getter();
    return 0;
}
