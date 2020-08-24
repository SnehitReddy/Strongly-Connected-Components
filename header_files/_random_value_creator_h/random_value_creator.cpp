#include <random>

RandomValueCreator::RandomValueCreator(){
    gen = std::mt19937(ran_device());
}

int RandomValueCreator::GetRandomValue(int lower, int upper){
    std::uniform_int_distribution<> dis(lower, upper);
    return dis(gen);
}



