#include <cmath>
#include <chrono>
#include <iostream>

using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using namespace std::literals::chrono_literals;

const unsigned int num_evals = 1000000000;
int main(int, const char**)
{    
    double val = M_PI/4;
    auto start = Clock::now();    
    for(unsigned i=0; i<num_evals; i++)
        sin(val);
    auto end = Clock::now();
    std::chrono::duration<double> elapsed_secs = end-start; 
    std::cout << "Elapsed time " << elapsed_secs.count()/num_evals * 1e9 << "ns" << std::endl;    

    return 0;
}