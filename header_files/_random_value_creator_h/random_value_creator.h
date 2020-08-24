#ifndef _random_value_creator_h
#define _random_value_creator_h

#include <random>

/// Class to handle <a href="http://www.cplusplus.com/reference/random/">random values generation</a> related operations in the program.
class RandomValueCreator
{
    public:
    
        /// Constructor to create initial seed value for random generator.
        RandomValueCreator();

        /// Function to create a random value between lower and upper limit provided by the user.
        ///
        /// Example
        /// ~~~~~~~~~~~~~~~~~~~~~~~~.cpp
        /// RandomValueCreator rvc = new RandomValueCreator();
        /// int randomValue = rvc.GetRandomValue({Lower Limit},{Upper Limit})
        /// ~~~~~~~~~~~~~~~~~~~~~~~~
        /// @param[in] lower Lower limit of the range in which random value has to be generated.
        /// @param[in] upper Upper limit of the range in which random value has to be generated.
        /// @return Random value between the provided limit (inclusive). 
        int GetRandomValue(int lower, int upper);

    private:
        std::random_device ran_device;
        std::mt19937 gen;
};

#include "random_value_creator.cpp"
#endif