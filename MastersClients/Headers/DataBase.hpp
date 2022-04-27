//
//  DataBase.hpp
//  MastersClients
//
//  Created by Dmytro Kovalenko on 27.04.2022.
//

#ifndef DataBase_h
#define DataBase_h

#include "DataKeeper.hpp"
#include "Tables.hpp"
#include <memory>

class DataBase{
public:
    DataBase();
    std::shared_ptr<DataKeeper<Client>> Get_client_db(){
        return client_db;
    }
    std::shared_ptr<DataKeeper<Service>> Get_service_db(){
        return serv_db;
    }
    std::shared_ptr<DataKeeper<Ownership>> Get_ownership_db(){
        return own_db;
    }
    std::shared_ptr<DataKeeper<Contract>> Get_contract_db(){
        return contr_db;
    }
    std::shared_ptr<DataKeeper<Device>> Get_device_db(){
        return device_db;
    }
    std::shared_ptr<DataKeeper<Master>> Get_master_db(){
        return master_db;
    }
private:
    std::shared_ptr<DataKeeper<Client>> client_db;//
    std::shared_ptr<DataKeeper<Service>> serv_db;//
    std::shared_ptr<DataKeeper<Ownership>> own_db;
    std::shared_ptr<DataKeeper<Contract>> contr_db;
    std::shared_ptr<DataKeeper<Device>> device_db;//
    std::shared_ptr<DataKeeper<Master>> master_db;
};

#endif /* DataBase_h */
