#include "main.h"
#include <iostream>
#include <boost/sort/heap_sort/heap_sort.hpp>
#include <boost/sort/spreadsort/integer_sort.hpp>
#include <boost/sort/block_indirect_sort/block_indirect_sort.hpp>
#include <boost/sort/spinsort/spinsort.hpp>
#include <boost/sort/flat_stable_sort/flat_stable_sort.hpp>
#include <boost/sort/pdqsort/pdqsort.hpp>
#include <vector>

int comparator(const void *a, const void *b) {
    if (a < b) return -1;
    else if (a == b) return 0;
    else return 1;
}

int main() {

    const long long N = 10000000;
    srand(time(NULL));
    std::vector<int> array(N);
    std::vector<int> arr(N);
    std::vector<int> arr2(N);
    std::vector<int> arr3(N);
    std::vector<int> arr4(N);
    std::vector<int> arr5(N);
    for (int i = 0; i < array.size(); i++) array[i] = rand();
    std::copy(array.begin(), array.end(), arr.begin());
    std::copy(array.begin(), array.end(), arr2.begin());
    std::copy(array.begin(), array.end(), arr3.begin());
    std::copy(array.begin(), array.end(), arr4.begin());
    std::copy(array.begin(), array.end(), arr5.begin());

    auto s_time = std::chrono::high_resolution_clock::now();
    std::sort(arr.begin(), arr.end());
    auto e_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(e_time - s_time);
    std::cout << "The std::sort time is " << double(duration.count() / 1000.0) << " seconds "<< std::endl;

    s_time = std::chrono::high_resolution_clock::now();
    boost::sort::spreadsort::integer_sort(arr2.begin(), arr2.end());
    e_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(e_time - s_time);
    std::cout << "The boost::integer_sort time is " << double(duration.count() / 1000.0) << " seconds "<< std::endl;

    s_time = std::chrono::high_resolution_clock::now();
    boost::sort::block_indirect_sort(arr3.begin(), arr3.end());
    e_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(e_time - s_time);
    std::cout << "The boost::block_indirect_sort time is " << double(duration.count() / 1000.0) << " seconds "<< std::endl;

    s_time = std::chrono::high_resolution_clock::now();
    boost::sort::pdqsort_branchless(arr4.begin(), arr4.end());
    e_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(e_time - s_time);
    std::cout << "The boost::pdqsort time is " << double(duration.count() / 1000.0) << " seconds "<< std::endl;

    return 0;
}