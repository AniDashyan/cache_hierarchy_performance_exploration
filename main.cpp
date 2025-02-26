#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <iomanip>
#include <string>

using namespace std::chrono;

const int size = 16 * 256 * 1024;
std::vector<int> strides = {1, 4, 16, 32, 64, 256, 1024};

template <typename T>
auto access_time(T& cont, int stride) {
    auto start = steady_clock::now();
    for (int i = 0; i < size; i++) {
    
    }
    auto end = steady_clock::now();
    return (duration_cast<milliseconds>(end - start).count());
}

template <typename T>
void print_output(T& cont, const std::string& c_name) {
    for (size_t i = 0; i < strides.size(); i++) {
        cout << c_name << " stride " << strides[i] << ": "
            << access_time(cont, strides[i]) << " ms\n";
    }
}

int main() {
    std::vector<int> vec(size);
    std::list<int> list(size);

    print_output(vec, "Vector");
    print_output(list, "List");
    return (0);
}