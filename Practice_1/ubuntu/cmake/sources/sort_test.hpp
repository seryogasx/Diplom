#ifndef sort_test_hpp
#define sort_test_hpp

#include <vector>
template <class T> double get_std_sort_time(std::vector<T> &);

template<class T> double get_boost_spread_sort_time(std::vector<T> &);

//template<class T> double get_boost_block_indirect_sort_time(std::vector<T> &);

//template<class T> double get_boost_pdqsort_sort_time(std::vector<T> &);

#include "sort_test.cpp"

#endif
