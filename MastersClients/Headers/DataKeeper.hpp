//
//  DataKeeper.hpp
//  MastersClients
//
//  Created by Dmytro Kovalenko on 24.04.2022.
//

#ifndef DataKeeper_h
#define DataKeeper_h

#include <map>
#include <iostream>
#include <memory>
template<typename T>
class DataKeeper{
    std::map<int, std::shared_ptr<T>> m_data; //id to element
public:
    bool Save(std::shared_ptr<T> element){
        if(!is_exist(element)){
            try{
                m_data[element->Get_ID()] = element;
                std::cout << "Successfull saving! ";
            } //add ID and name of table!!!!!!!!!!!!
            catch(...){
                std::cerr << "Saving Error!" << std::endl;
                return false;
            }
            return true;
        }
        else{
            std::cerr << "Element exists(" << std::endl;
            return false;
        }
    }
    
    bool is_exist(std::shared_ptr<T> element){
        if(m_data.find(element->Get_ID()) == m_data.end()){
            return false;
        }
        return true;
    }
};
#endif /* DataKeeper_h */
