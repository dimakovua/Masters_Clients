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
