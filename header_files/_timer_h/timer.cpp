#include <chrono>

void ExecutionTime::StartTimer(){
    start = std::chrono::high_resolution_clock::now();
}

void ExecutionTime::StopTimer(){
    stop = std::chrono::high_resolution_clock::now();
}

auto ExecutionTime::CalculateExecutionTime(){
    duration = std::chrono::duration_cast<std::chrono::microseconds> (stop-start);
    return duration.count();
}