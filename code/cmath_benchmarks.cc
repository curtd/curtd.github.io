#include <cmath>
#include <chrono>
#include <iostream>
#include <random>

using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using namespace std::literals::chrono_literals;

const unsigned int num_evals = 1000000000;
int main(int, const char**)
{    
    std::default_random_engine generator;
    std::normal_distribution<double> distribution;
    double val = distribution(generator);
    auto start = Clock::now();    
    for(unsigned i=0; i<num_evals; i++)
        sin(val);
    auto end = Clock::now();
    std::chrono::duration<double> elapsed_secs = end-start; 
    std::cout << "Elapsed time " << elapsed_secs.count()/num_evals * 1e9 << "ns" << std::endl;    

    return 0;
}