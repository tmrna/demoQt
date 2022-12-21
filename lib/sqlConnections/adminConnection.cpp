#include "adminConnection.hpp"


adminConnection::adminConnection(){
    query = nullptr;

}


adminConnection::~adminConnection(){
    if(query != nullptr){
        delete query;
    }
}
