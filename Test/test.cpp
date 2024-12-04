#include "test.hpp"

void psudoDB::createData(){
        
    for(long int i=0;i<1000;i++){
        db.push_back(i);
    }
}


psudoDB::psudoDB(){
    createData();
};

long int psudoDB::get(long int number){
    for(long int i = 0; i < db.size();i++){
        if(db[i] == number){
            // add delay of 2 seconds
            std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::nanoseconds(500));
            return i;
        }
    }
    // add delay of 2 seconds
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::nanoseconds(500));
    return -1;
}
