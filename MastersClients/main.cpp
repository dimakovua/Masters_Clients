#include <iostream>
#include "Headers/Tables.hpp"
#include "Headers/DataKeeper.hpp"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Client aboba("Dmytro", "Kovalenko", "Yuriyovych", "+380990288191", "email", "abobacard");
    Client aboba1("Dmytro", "Kovalenko", "Yuriyovych", "+380990288191", "email", "abobacard");
    std::cout << aboba.Get_ID() << " " << aboba1.Get_ID() << std::endl;
    Service serv("Name", "time", "cost");
    Service serv1("Name", "time", "cost");
    std::cout << "\n" << serv.Get_ID() << " " << serv1.Get_ID() << std::endl;
    Ownership own(1, 2);
    std::cout << own.Get_ID() << std::endl;
    Contract contr(10, 15, 14, "aboba", "aboba");
    DataKeeper<Client> client_db;
    client_db.Save(aboba);
    client_db.Save(aboba1);
    DataKeeper<Service> serv_db;
    DataKeeper<Ownership> own_db;
    DataKeeper<Contract> contr_db;
    serv_db.Save(serv);
    serv_db.Save(serv1);
    own_db.Save(own);
    contr_db.Save(contr);
    return 0;
}
