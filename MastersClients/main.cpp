#include <iostream>
#include "Headers/Tables.hpp"
#include "Headers/DataKeeper.hpp"
#include "Headers/Tools.hpp"
#include "Headers/Interface.hpp"
int main(int argc, const char * argv[]) {

    DataKeeper<Client> client_db;//
    DataKeeper<Service> serv_db;//
    DataKeeper<Ownership> own_db;
    DataKeeper<Contract> contr_db;
    DataKeeper<Device> device_db;//
    DataKeeper<Master> master_db;
    
    auto client_one = std::make_shared<Client>("Dmytro", "Kovalenko", "Yuriyovych", "+380990288191", "email", "abobacard");
    auto client_two = std::make_shared<Client>("Alex", "Yemets", "Aboba", "+3809902191", "paper", "AHAHAcard");
    
    auto master_one = std::make_shared<Master>("MasterName", "MasterLastname", "MasterFather", "MasterPhone", "120", "1000");
    auto master_two = std::make_shared<Master>("MasterName2", "MasterLastname2", "MasterFather2", "MasterPhone2", "100", "1500");
    
    auto device_one = std::make_shared<Device>("iphone", "seven", "it's broken");
    auto device_two = std::make_shared<Device>("xiaomi", "wow", "it's not broken");
    
    auto service_one = std::make_shared<Service>("Name", "time", "cost");
    auto service_two = std::make_shared<Service>("Notname", "nottime", "fuckcost");
    
    auto contract_one = std::make_shared<Contract>(10, 15, 14, "aboba", "aboba");
    auto ownership_one = std::make_shared<Ownership>(1,2);
    
    client_db.Save(client_one);
    client_db.Save(client_two);
    
    serv_db.Save(service_one);
    serv_db.Save(service_two);
    
    device_db.Save(device_one);
    device_db.Save(device_two);
    
    own_db.Save(ownership_one);
    
    master_db.Save(master_one);
    master_db.Save(master_two);
    
    contr_db.Save(contract_one);
    Tools aboba;
    bool a = aboba.Add_m("MASTER", {"peter", "a", "b", "c", "d", "e"});
    std::cout << "=======" << a << std::endl;
    
    Interface interf;
    interf.Command_getter();
    return 0;
}
