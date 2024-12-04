#include "cache.hpp"
#include <algorithm>
#include <vector>
#include <iostream>

Cache::Cache(){
    capacity = maxNUmberOfEntries;
}

int Cache::findLeastRecentlyUsedKey(){
    if(accessOrder.empty()) return -1;
    return accessOrder.back();
}

void Cache::updateAcessOrder(int key){
    auto it = std::find(accessOrder.begin(),accessOrder.end(),key);
    if(it != accessOrder.end()){
        accessOrder.erase(it);
    }
    accessOrder.insert(accessOrder.begin(),key);
}

void Cache::evictLeastRecentlyUsedKey(){
    if(accessOrder.size() > maxNUmberOfEntries){
        int lrukey = findLeastRecentlyUsedKey();
        if(lrukey != -1){
            SkipList.remove(lrukey);
            accessOrder.pop_back();
        }
    }
}

void Cache::put(int key){

    evictLeastRecentlyUsedKey();

    SkipList.insert(key);

    updateAcessOrder(key);
}

int Cache::get(int key){
    auto value = SkipList.search(key);

    if(value) updateAcessOrder(key);

    return value;
}
