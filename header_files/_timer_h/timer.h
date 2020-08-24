#ifndef _timer_h
#define _timer_h

#include<chrono>

///Class to handle <a href= "https://www.geeksforgeeks.org/measure-execution-time-function-cpp/">Execution Time Calculation</a> related queries in the program.
class ExecutionTime{

    public :

        ///Function to get the system time when statement(s) start its execution.
        ///
        ///This function should be called before the statement/block whose execution time is required or needs to be calculated.
        /// #### Example
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
        /// ExecutionTime t;
        /// t.StartTimer();
        ///     // Block of code 
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ///@return Starting time of the next statement in the line of execution.
        ///@see StopTimer()
        ///@see CalculateExecutionTime()
        void StartTimer();

        ///Function to get the system time after statement(s) have finished execution.
        ///
        ///This function should be called after the statement/block whose execution time is required or needs to be calculated.
        /// #### Example
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
        /// ExecutionTime t;
        /// t.StartTimer();
        ///     // Block of code
        /// t.StopTimer(); 
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ///@return Time at which the execution of previous statement(s) was completed.
        ///@see StopTimer()
        ///@see CalculateExecutionTime()
        void StopTimer();

        ///Function to calculate execution time of a statement in C++.
        ///
        /// #### Example
        /// ~~~~~~~~~~~~~~~~~~~~~~~~.cpp
        /// ExecutionTime t;
        /// t.StartTime();
        ///     // Block of code 
        /// t.StopTimer();
        /// std::cout<<t.CalculateExecutionTime();
        /// ~~~~~~~~~~~~~~~~~~~~~~~~
        ///@return Execution time of the block surrounded by StartTimer() and StopTimer()
        ///@see StartTimer()
        ///@see StopTimer()
        auto CalculateExecutionTime();

    private :
        std::chrono::time_point<std::chrono::high_resolution_clock> start; /** Stores the start time of a C++ statement execution. */
        std::chrono::time_point<std::chrono::high_resolution_clock> stop; /** Stores the end time of a C++ statement completion. */
        std::chrono::microseconds duration; /** Stores the duration for which a C++ statement is executed. */

};

#include "timer.cpp"
#endif


