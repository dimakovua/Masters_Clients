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
    //std::cout << "I M HERE!\n";
    
    std::string line;
    std::ifstream file("/Users/dmytrokovalenko/Documents/MastersClients/saving.txt");
    if(file.is_open()){
        while(file){
            std::getline(file, line);
            Open_file(line);
        }
    }
}
std::string DataBase::Parse_stick(std::string& line){
    std::string result;
    auto stick_iter = std::find(line.begin(), line.end(), '|');
    if(stick_iter == line.end()){
        //std::cout << line << "\n";
        return line;
    }
    else{
        result = std::string(line.begin(), stick_iter);
        line.erase(line.begin(), stick_iter+1);
        //std::cout << result << "\n";
    }
    return result;
}
void DataBase::Open_file(std::string line){
//    while(1){
//        if(line == Parse_stick(line)) break;
//    }
    std::string table = Parse_stick(line);
    if(table == "MASTERS"){
        auto id = Parse_stick(line);
        auto el = make_shared<Master>(Parse_stick(line), Parse_stick(line), Parse_stick(line), Parse_stick(line), Parse_stick(line), Parse_stick(line)); //LOL WHAT'S THE CODE!!
        if(el->Get_ID() != std::stoi(id)){
            el->Change_ID(std::stoi(id));
        }
        master_db->Save(el);
    }
    else if(table == "CLIENTS"){
        auto id = Parse_stick(line);
        auto el = make_shared<Client>(Parse_stick(line), Parse_stick(line), Parse_stick(line), Parse_stick(line), Parse_stick(line), Parse_stick(line)); //LOL WHAT'S THE CODE!!
        if(el->Get_ID() != std::stoi(id)){
            el->Change_ID(std::stoi(id));
        }
        client_db->Save(el);
    }
    else if(table == "DEVICE"){
        auto id = Parse_stick(line);
        auto el = make_shared<Device>(Parse_stick(line), Parse_stick(line), Parse_stick(line)); //LOL WHAT'S THE CODE!!
        if(el->Get_ID() != std::stoi(id)){
            el->Change_ID(std::stoi(id));
        }
        device_db->Save(el);
    }
    else if(table == "SPECIALIZATION"){
        auto id = Parse_stick(line);
        auto el = make_shared<Specialization>(Parse_stick(line), Parse_stick(line)); //LOL WHAT'S THE CODE!!
        if(el->Get_ID() != std::stoi(id)){
            el->Change_ID(std::stoi(id));
        }
        special_db->Save(el);
    }
    else if(table == "SERVICE"){
        auto id = Parse_stick(line);
        auto el = make_shared<Service>(Parse_stick(line), Parse_stick(line), Parse_stick(line)); //LOL WHAT'S THE CODE!!
        if(el->Get_ID() != std::stoi(id)){
            el->Change_ID(std::stoi(id));
        }
        serv_db->Save(el);
    }
    else if(table == "OWNERSHIP"){
        auto id = Parse_stick(line);
        auto el = make_shared<Ownership>(Parse_stick(line), Parse_stick(line)); //LOL WHAT'S THE CODE!!
        if(el->Get_ID() != std::stoi(id)){
            el->Change_ID(std::stoi(id));
        }
        own_db->Save(el);
    }
    else if(table == "CONTRACT"){
        auto id = Parse_stick(line);
        auto el = make_shared<Contract>(Parse_stick(line), Parse_stick(line), Parse_stick(line), Parse_stick(line), Parse_stick(line)); //LOL WHAT'S THE CODE!!
        if(el->Get_ID() != std::stoi(id)){
            el->Change_ID(std::stoi(id));
        }
        contr_db->Save(el);
    }
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
//    if(!file.is_open()){
//        std::cout << "ERROR!";
//    }
//    else std::cout << "not error";
    if(file.is_open()){
        //file << "ABOBA!";
        for(auto i : master_db->m_data){
            file << "MASTERS|";
            file << i.second->Get_ID() << "|" << i.second->Get_first_name() << "|" << i.second->Get_last_name() << "|" << i.second->Get_father_name() << "|" <<
            i.second->Get_phone_number() << "|" << i.second->Get_experience() << "|" << i.second->Get_Salary() << "\n";
        }
        for(auto i : client_db->m_data){
            file << "CLIENTS|";
            file << i.second->Get_ID() << "|" << i.second->Get_first_name() << "|" << i.second->Get_last_name() << "|" << i.second->Get_father_name() << "|" << i.second->Get_phone_number() << "|" << i.second->Get_email() << "|" << i.second->Get_card() << "\n";
        }
        for(auto i : device_db->m_data){
            file << "DEVICE|";
            file << i.second->Get_ID() << "|" << i.second->Get_name() << "|" << i.second->Get_model() << "|" << i.second->Get_breakage() << "\n";
        }
        for(auto i : serv_db -> m_data){
            file << "SERVICE|";
            file << i.second->Get_ID() << "|" << i.second->Get_name() << "|" << i.second->Get_time() << "|" << i.second->Get_cost() << "\n";
        }
        for(auto i : own_db->m_data){
            file << "OWNERSHIP|";
            file << i.second->Get_ID() << "|" << i.second->Get_owner_id() << "|" << i.second->Get_device_id() << "\n";
        }
        for(auto i : special_db->m_data){
            file << "SPECIALIZATION|";
            file << i.second->Get_ID() << "|" << i.second->Get_master_id() << "|" << i.second->Get_service_id() << "\n";
        }
        for(auto i : contr_db->m_data){
            file << "CONTRACT|";
            file << i.second->Get_ID() << "|" << i.second->Get_service_id() << "|" <<  i.second->Get_master_id() << "|" << i.second->Get_client_id() << "|" << i.second->Get_date() << "|" << i.second->Get_status() << "\n";
        }
        file.close();
        std::cout << "Saved!\nBye! :)\n";
    }
    else{
        std::cout << "Error while reading savings!\n";
    }
}
