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
    special_db = std::make_shared<DataKeeper<Specialization>>();
    std::cout << "I M HERE!\n";
}

std::shared_ptr<DataKeeper<Specialization>> DataBase::Get_special_db(){
    return special_db;
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

DataBase::~DataBase(){
    std::ofstream file;
    file.open("/Users/dmytrokovalenko/Documents/MastersClients/saving.txt");
    if(!file.is_open()){
        std::cout << "ERROR!";
    }
    else std::cout << "not error";
    //file << "ABOBA!";
    file << "MASTERS\n";
    for(auto i : master_db->m_data){
        file << i.second->Get_ID() << "|" << i.second->Get_first_name() << "|" << i.second->Get_last_name() << "|" << i.second->Get_father_name() << "|" << i.second->Get_experience() << "|" << i.second->Get_Salary() << "\n";
    }
    file << "CLIENTS\n";
    for(auto i : client_db->m_data){
        file << i.second->Get_ID() << "|" << i.second->Get_first_name() << "|" << i.second->Get_last_name() << "|" << i.second->Get_father_name() << "|" << i.second->Get_card() << "|" << i.second->Get_phone_number() << "\n";
    }
    file << "DEVICE\n";
    for(auto i : device_db->m_data){
        file << i.second->Get_ID() << "|" << i.second->Get_name() << "|" << i.second->Get_model() << "|" << i.second->Get_breakage() << "\n";
    }
    file << "SERVICE\n";
    for(auto i : serv_db -> m_data){
        file << i.second->Get_ID() << "|" << i.second->Get_name() << "|" << i.second->Get_cost() << "|" << i.second->Get_time() << "\n";
    }
    file << "OWNERSHIP\n";
    for(auto i : own_db->m_data){
        file << i.second->Get_ID() << "|" << i.second->Get_owner_id() << "|" << i.second->Get_device_id() << "\n";
    }
    file << "SPECIALIZATION\n";
    for(auto i : special_db->m_data){
        file << i.second->Get_ID() << "|" << i.second->Get_master_id() << "|" << i.second->Get_service_id() << "\n";
    }
    file << "CONTRACT\n";
    for(auto i : contr_db->m_data){
        file << i.second->Get_ID() << "|" << i.second->Get_service_id() << "|" <<  i.second->Get_master_id() << "|" << i.second->Get_client_id() << "|" << i.second->Get_date() << "|" << i.second->Get_status() << "\n";
    }
    file.close();
}
