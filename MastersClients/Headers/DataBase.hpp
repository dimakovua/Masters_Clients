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
    std::shared_ptr<DataKeeper<Client>> Get_client_db();
    std::shared_ptr<DataKeeper<Service>> Get_service_db();
    std::shared_ptr<DataKeeper<Ownership>> Get_ownership_db();
    std::shared_ptr<DataKeeper<Contract>> Get_contract_db();
    std::shared_ptr<DataKeeper<Device>> Get_device_db();
    std::shared_ptr<DataKeeper<Master>> Get_master_db();
    std::shared_ptr<DataKeeper<Specialization>> Get_special_db();
    ~DataBase();
private:
    std::string Parse_stick(std::string& line);
    void Open_file(std::string line);
    std::shared_ptr<DataKeeper<Specialization>> special_db;
    std::shared_ptr<DataKeeper<Client>> client_db;//
    std::shared_ptr<DataKeeper<Service>> serv_db;//
    std::shared_ptr<DataKeeper<Ownership>> own_db;
    std::shared_ptr<DataKeeper<Contract>> contr_db;
    std::shared_ptr<DataKeeper<Device>> device_db;//
    std::shared_ptr<DataKeeper<Master>> master_db;
};

#endif /* DataBase_h */
