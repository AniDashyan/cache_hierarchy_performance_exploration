#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <iomanip>
#include <string>

using namespace std::chrono;

const int size = 16 * 256 * 1024 * 64;
std::vector<int> strides = {1, 4, 16, 32, 64, 256, 1024};

template <typename T>
auto access_time(T& cont, int stride) {
    int sum = 0;
    auto it = cont.begin();

    auto start = steady_clock::now();
    while (it != cont.end()) {
        sum += *it;
        std::advance(it, stride);
    }
    auto end = steady_clock::now();
    return (duration_cast<milliseconds>(end - start).count());
}


int main() {
    std::vector<int> vec(size);
    std::list<int> list(size);

    std::cout << std::left << std::setw(5) << "Stride" 
              << std::right << std::setw(10) << "Vector" 
              << std::right << std::setw(10) << "List" << "\n";
    std::cout << std::string(30, '-') << "\n"; 


    for (size_t i = 0; i < strides.size(); i++) {
        std::cout << std::right << std::setw(5) << strides[i]
                  << std::right << std::setw(10) << access_time(vec, strides[i]) << " ms"
                  << std::right << std::setw(10) << access_time(list, strides[i]) << " ms\n";
    }
    return (0);
}