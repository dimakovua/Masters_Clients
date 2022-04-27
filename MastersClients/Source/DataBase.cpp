//
//  DataBase.cpp
//  MastersClients
//
//  Created by Dmytro Kovalenko on 27.04.2022.
//

#include "../Headers/DataBase.hpp"

DataBase::DataBase(){
    client_db = std::make_shared<DataKeeper<Client>>();
    serv_db = std::make_shared<DataKeeper<Service>>();
    own_db = std::make_shared<DataKeeper<Ownership>>();
    contr_db = std::make_shared<DataKeeper<Contract>>();
    device_db = std::make_shared<DataKeeper<Device>>();
    master_db = std::make_shared<DataKeeper<Master>>();
}

std::shared_ptr<DataKeeper<Client>> DataBase::Get_client_db(){
    return client_db;
}
std::shared_ptr<DataKeeper<Service>> DataBase::Get_service_db(){
    return serv_db;
}
std::shared_ptr<DataKeeper<Ownership>> DataBase::Get_ownership_db(){
    return own_db;
}
std::shared_ptr<DataKeeper<Contract>> DataBase::Get_contract_db(){
    return contr_db;
}
std::shared_ptr<DataKeeper<Device>> DataBase::Get_device_db(){
    return device_db;
}
std::shared_ptr<DataKeeper<Master>> DataBase::Get_master_db(){
    return master_db;
}
