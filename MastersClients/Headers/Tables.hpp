
#ifndef Tables_h
#define Tables_h

#include <string>
#include <map>
class Client{
private:
    std::string m_last_name;
    std::string m_first_name;
    std::string m_father_name;
    std::string m_phone_number;
    static int Client_ID;
    int m_id;
    std::string m_email;
    std::string m_card;
public:
    Client(){
        
    }
    Client(std::string first_name, std::string last_name, std::string father_name, std::string phone_number, std::string email, std::string card) : m_last_name(last_name), m_first_name(first_name), m_father_name(father_name), m_phone_number(phone_number), m_email(email), m_card(card) {
        Client_ID++;
        m_id = Client_ID;
    }
    std::string Get_last_name(){
        return m_last_name;
    }
    std::string Get_first_name(){
        return m_first_name;
    }
    std::string Get_father_name(){
        return m_father_name;
    }
    std::string Get_phone_number(){
        return m_phone_number;
    }
    std::string Get_email(){
        return m_email;
    }
    std::string Get_card(){
        return m_card;
    }
    int Get_ID(){
        return m_id;
    }
    std::string Get_table_name(){
        return "Client";
    }
};



class Master{
private:
    std::string m_last_name;
    std::string m_first_name;
    std::string m_father_name;
    std::string m_phone_number;
    static int Master_ID;
    int m_id;
    std::string m_experience;
    std::string m_salary;
    std::string m_card;
public:
    Master(){
        
    }
    Master(std::string first_name, std::string last_name, std::string father_name, std::string phone_number, std::string exp,  std::string salary) : m_last_name(last_name), m_first_name(first_name), m_experience(exp), m_father_name(father_name), m_phone_number(phone_number), m_salary(salary){
        Master_ID++;
        m_id = Master_ID;
    }
    
    std::string Get_last_name(){
        return m_last_name;
    }
    std::string Get_first_name(){
        return m_first_name;
    }
    std::string Get_father_name(){
        return m_father_name;
    }
    std::string Get_phone_number(){
        return m_phone_number;
    }
    std::string Get_experience(){
        return m_experience;
    }
    std::string Get_Salary(){
        return m_salary;
    }
    int Get_ID(){
        return m_id;
    }
    std::string Get_table_name(){
        return "Master";
    }
};

class Device{
    static int Device_ID;
    int m_id;
    std::string m_name;
    std::string m_model;
    std::string m_breakage;
public:
    Device(){
        
    }
    Device(std::string name, std::string model, std::string breakage) : m_name(name), m_model(model), m_breakage(breakage){
        Device_ID++;
        m_id = Device_ID;
    }
    std::string Get_name(){
        return m_name;
    }
    std::string Get_model(){
        return m_model;
    }
    std::string Get_breakage(){
        return m_breakage;
    }
    int Get_ID(){
        return m_id;
    }
    std::string Get_table_name(){
        return "Device";
    }
};

class Service{
private:
    std::string m_service_name;
    std::string m_time;
    std::string m_cost;
    static int Service_ID;
    int m_id;
public:
    Service(){
        
    }
    Service(std::string service_name, std::string time, std::string cost) : m_service_name(service_name), m_time(time), m_cost(cost){
        Service_ID++;
        m_id = Service_ID;
    }
    std::string Get_name(){
        return m_service_name;
    }
    std::string Get_time(){
        return m_time;
    }
    std::string Get_cost(){
        return m_cost;
    }
    int Get_ID(){
        return m_id;
    }
    std::string Get_table_name(){
        return "Service";
    }
};

class Ownership{
    static int Ownership_ID;
    int m_id;
    std::string m_owner_id;
    std::string m_device_id;
public:
    Ownership(){
        
    }
    Ownership(std::string owner_id, std::string device_id) : m_owner_id(owner_id), m_device_id(device_id){
        Ownership_ID++;
        m_id = Ownership_ID;
    }
    std::string Get_owner_id(){
        return m_owner_id;
    }
    std::string Get_device_id(){
        return m_device_id;
    }
    int Get_ID(){
        return m_id;
    }
    std::string Get_table_name(){
        return "Ownership";
    }
};

class Specialization{
    static int Specialization_ID;
    int m_id;
    std::string m_master_id;
    std::string m_service_id;
public:
    Specialization(){
        
    }
    Specialization(std::string master_id, std::string service_id) : m_master_id(master_id), m_service_id(service_id){
        Specialization_ID++;
        m_id = Specialization_ID;
    }
    std::string Get_master_id(){
        return m_master_id;
    }
    std::string Get_service_id(){
        return m_service_id;
    }
    int Get_ID(){
        return m_id;
    }
    std::string Get_table_name(){
        return "Specialization";
    }
};

class Contract{
    static int Contract_ID;
    int m_id;
    std::string m_service_id;
    std::string m_master_id;
    std::string m_client_id;
    std::string m_date;
    std::string m_status;
    
public:
    Contract(){
        
    }
    Contract(std::string service_id, std::string master_id, std::string client_id, std::string date, std::string status) : m_service_id(service_id), m_master_id(master_id), m_client_id(client_id), m_date(date), m_status(status){
        Contract_ID++;
        m_id = Contract_ID;
    }
    std::string Get_service_id(){
        return m_service_id;
    }
    std::string Get_master_id(){
        return m_master_id;
    }
    std::string Get_client_id(){
        return m_client_id;
    }
    int Get_ID(){
        return m_id;
    }
    std::string Get_date(){
        return m_date;
    }
    std::string Get_status(){
        return m_status;
    }
    std::string Get_table_name(){
        return "Contract";
    }
};
#endif /* Tables_h */
