//
//  Tools.cpp
//  MastersClients
//
//  Created by Dmytro Kovalenko on 27.04.2022.
//

#include "../Headers/Tools.hpp"

Tools::Tools(){
    m_db = std::make_unique<DataBase>();
}

bool Tools::Add_m(std::string table_name, std::vector<std::string> args){
    if(table_name == "MASTER"){
        if(args.size() != 6){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_master_db()->Save(std::make_shared<Master>(args[0], args[1], args[2], args[3], args[4], args[5]));
            return true;
        }
    }
    else if(table_name == "CLIENT"){
        if(args.size() != 6){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_client_db()->Save(std::make_shared<Client>(args[0], args[1], args[2], args[3], args[4], args[5]));
            return true;
        }
    }
    else if(table_name == "DEVICE"){
        if(args.size() != 3){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_device_db()->Save(std::make_shared<Device>(args[0], args[1], args[2]));
            return true;
        }
    }
    else if(table_name == "SERVICE"){
        if(args.size() != 3){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_service_db()->Save(std::make_shared<Service>(args[0], args[1], args[2]));
            return true;
        }
    }
    else if(table_name == "CLIENT"){
        if(args.size() != 6){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_client_db()->Save(std::make_shared<Client>(args[0], args[1], args[2], args[3], args[4], args[5]));
            return true;
        }
    }
    else if(table_name == "OWNERSHIP"){
        if(args.size() != 2){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_ownership_db()->Save(std::make_shared<Ownership>(args[0], args[1]));
            return true;
        }
    }
    else if(table_name == "SPECIALIZATION"){
        if(args.size() != 2){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_special_db()->Save(std::make_shared<Specialization>(args[0], args[1]));
            return true;
        }
    }
    else if(table_name == "CONTRACT"){
        if(args.size() != 5){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_contract_db()->Save(std::make_shared<Contract>(args[0], args[1], args[2], args[3], args[4]));
            return true;
        }
    }
    else{
        throw std::runtime_error("Unknown table");
        return false;
    }
}
