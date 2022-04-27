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

void Tools::Get_m(std::string table_name, std::string id){
    int ID = std::stoi(id);
    if(table_name == "MASTER"){
        auto el = m_db->Get_master_db()->Get(ID);
        std::cout << "---Master-" << el->Get_ID() << "---\n" << "First name:\t" << el->Get_first_name() << "\nLast name:\t" << el->Get_last_name() << "\nFather name:\t" << el->Get_father_name() << "\nPhone number:\t" << el->Get_phone_number() << "\nSalary:\t"<< el->Get_Salary() << "\nExperience:\t" << el->Get_experience() << std::endl;
    }
    else if(table_name == "CLIENT"){
        auto el = m_db->Get_client_db()->Get(ID);
        std::cout << "---Client-" << el->Get_ID() << "---\n" << "First name:\t" << el->Get_first_name() << "\nLast name:\t" << el->Get_last_name() << "\nFather name:\t" << el->Get_father_name() << "\nPhone number:\t" << el->Get_phone_number() << "\nCard:\t"<< el->Get_card() << "\nEmail:\t" << el->Get_email()<< std::endl;
    }
    else if(table_name == "DEVICE"){
        auto el = m_db->Get_device_db()->Get(ID);
        std::cout << "---Device-" << el->Get_ID() << "---\n" << "Name:\t" << el->Get_name() << "\nModel:\t" << el->Get_model() << "\nBreakage:\t" << el->Get_breakage()<< std::endl;
    }
    else if(table_name == "OWNERSHIP"){
        auto el = m_db->Get_ownership_db()->Get(ID);
        std::cout << "---Ownership-" << el->Get_ID() << "---\n" << "Owner ID:\t" << el->Get_owner_id() << "\nDevice ID:\t" << el->Get_device_id() << std::endl;
    }
    else if(table_name == "SERVICE"){
        auto el = m_db->Get_service_db()->Get(ID);
        std::cout << "---Service-" << el->Get_ID() << "---\n" << "Service Name:\t" << el->Get_name() << "\nTime:\t" << el->Get_time() <<"\nCost:\t" << el->Get_cost() << std::endl;
    }
    else if(table_name == "SPECIALIZATION"){
        auto el = m_db->Get_special_db()->Get(ID);
        std::cout << "---Specialization-" << el->Get_ID() << "---\n" << "Master ID:\t" << el->Get_master_id() << "\nService ID:\t" << el->Get_service_id() << std::endl;
    }
    else if(table_name == "CONTRACT"){
        auto el = m_db->Get_contract_db()->Get(ID);
        std::cout << "---Contract-" << el->Get_ID() << "---\n" << "Master ID:\t" << el->Get_master_id() << "\nClient ID:\t" << el->Get_client_id() <<"\nService ID:\t" << el->Get_service_id() <<"\nDate:\t" << el->Get_date() << "\nStatus:\t" << el->Get_status() << std::endl;
    }
    else{
        throw std::runtime_error("Unknown table");
    }
}
