#include <iostream>
#include "Headers/Tables.hpp"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Client aboba("Dmytro", "Kovalenko", "Yuriyovych", "+380990288191", "email", "abobacard");
    Client aboba1("Dmytro", "Kovalenko", "Yuriyovych", "+380990288191", "email", "abobacard");
    std::cout << aboba.Get_ID() << " " << aboba1.Get_ID() << std::endl;
    Service serv("Name", "time", "cost");
    Service serv1("Name", "time", "cost");
    std::cout << "\n" << serv.Get_ID() << " " << serv1.Get_ID() << std::endl;
    return 0;
}
