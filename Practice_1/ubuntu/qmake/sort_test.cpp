#ifndef sort_test_cpp
#define sort_test_cpp

#include "sort_test.hpp"
#include <boost/sort/heap_sort/heap_sort.hpp>
#include <boost/sort/spreadsort/integer_sort.hpp>
#include <boost/sort/block_indirect_sort/block_indirect_sort.hpp>
#include <boost/sort/spinsort/spinsort.hpp>
#include <boost/sort/flat_stable_sort/flat_stable_sort.hpp>
#include <boost/sort/pdqsort/pdqsort.hpp>

template<class T>
double get_std_sort_time(std::vector<T> &vec) {
    auto s_time = std::chrono::high_resolution_clock::now();
    std::sort(vec.begin(), vec.end());
    auto e_time = std::chrono::high_resolution_clock::now();
    return double(std::chrono::duration_cast<std::chrono::milliseconds>(e_time - s_time).count() / 1000.0);
}

template<class T>
double get_boost_spread_sort_time(std::vector<T> &vec) {
    auto s_time = std::chrono::high_resolution_clock::now();
    boost::sort::spreadsort::integer_sort(vec.begin(), vec.end());
    auto e_time = std::chrono::high_resolution_clock::now();
    return double(std::chrono::duration_cast<std::chrono::milliseconds>(e_time - s_time).count() / 1000.0);
}

template<class T>
double get_boost_block_indirect_sort_time(std::vector<T> &vec) {
    auto s_time = std::chrono::high_resolution_clock::now();
    boost::sort::block_indirect_sort(vec.begin(), vec.end());
    auto e_time = std::chrono::high_resolution_clock::now();
    return double(std::chrono::duration_cast<std::chrono::milliseconds>(e_time - s_time).count() / 1000.0);
}

template<class T>
double get_boost_pdqsort_sort_time(std::vector<T> &vec) {
    auto s_time = std::chrono::high_resolution_clock::now();
    boost::sort::pdqsort(vec.begin(), vec.end());
    auto e_time = std::chrono::high_resolution_clock::now();
    return double(std::chrono::duration_cast<std::chrono::milliseconds>(e_time - s_time).count() / 1000.0);
}

#endif