#include <iostream>
#include "./Core/cache.hpp"
#include "test.hpp"
#include <random>

int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long int> dis(1,1000);

    int cacheHit = 0;
    int cacheMiss = 0;
    auto start = std::chrono::system_clock::now();
    
    Cache cache;
    psudoDB pdb;

    for(int j =0; j<10;j++){
        for(int i = 0; i < 1000000; i++){
            long int key = dis(gen);

            auto value = cache.get(key);
            if(value != -1){
                cacheHit++;
            }else{
                cacheMiss++;
                cache.put(key);
                pdb.get(key);
            }
        }

    }
    
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;

    std::cout<<"Cache Hit Count: "<<cacheHit<<std::endl;
    std::cout<<"Cache Miss Count: "<<cacheMiss<<std::endl;
    std::cout<<"Time taken for the program to run: "<<diff.count()<<std::endl;
    cache.SkipList.display();
    return 0;
}