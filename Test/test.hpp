#include <vector>
#include <random>
#include <chrono>
#include <thread>

class psudoDB{
private:
    std::vector<int> db;

    void createData();

public:
    psudoDB();

    long int get(long int number);
};