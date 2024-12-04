#include "../Lib/skiplist.hpp"
#include <vector>
#include <optional>

const int maxNUmberOfEntries = 10;

class Cache{
private:

    
    int capacity;

    std::vector<int> accessOrder;

    int findLeastRecentlyUsedKey();

    void updateAcessOrder(int key);

    void evictLeastRecentlyUsedKey();

public:
    skipList SkipList;
    Cache();

    void put(int key);

    int get(int key);

    //bool remove(int key);
};

