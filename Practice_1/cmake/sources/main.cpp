#include "sort_test.hpp"
#include <iostream>

template<class T>
void swap(T &a, T&b) {
    T tmp = a;
    a = b;
    b = tmp;
}


template<class T>
bool check_sort(std::vector<T> &a) {
    for (int i = 1; i < a.size(); i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}


template<class T>
std::vector<std::pair<std::string, double> > test_sorting(std::vector<T> &a, std::vector<T> &b, std::vector<T> &c, std::vector<T> &d) {
    std::vector<std::pair<std::string, double> > results;

    auto time = get_std_sort_time<int>(a);
    std::pair<std::string, double> pair = check_sort(a) ? std::make_pair("std::sort", time) : std::make_pair("std::sort ERROR!", time);
    results.push_back(pair);

    time = get_boost_spread_sort_time<int>(b);
    pair = check_sort(b) ? std::make_pair("boost::spread", time) : std::make_pair("boost::spread ERROR!", time);
    results.push_back(pair);
    
    time = get_boost_block_indirect_sort_time<int>(c);
    pair = check_sort(c) ? std::make_pair("boost::block_indirect", time) : std::make_pair("boost::block_indirect ERROR!", time);
    results.push_back(pair);
    
    time = get_boost_pdqsort_sort_time<int>(d);
    pair = check_sort(d) ? std::make_pair("boost::pdqsort", time) : std::make_pair("boost::pdqsort ERROR!", time);
    results.push_back(pair);
    return results;
}


int main() {

    const long long N = 5000000;
    std::cout << "Size: " << N << " elems" << std::endl;
    srand(time(NULL));
    std::vector<int> array(N);
    std::vector<int> arr(N), arr2(N), arr3(N), arr4(N);
    for (int i = 0; i < array.size(); i++){
        auto tmp = rand();
        arr[i] = tmp;
        arr2[i] = tmp;
        arr3[i] = tmp;
        arr4[i] = tmp;
    }

    std::cout << std::endl <<  "Random:" << std::endl;
    auto results = test_sorting(arr, arr2, arr3, arr4);
    for (auto i : results)
        std::cout << i.first << " -> " << i.second << std::endl;

    std::cout << std::endl << "Already sorted:" << std::endl;
    results = test_sorting(arr, arr2, arr3, arr4);
    for (auto i : results)
        std::cout << i.first << " -> " << i.second << std::endl;

    for (int i = 0; i < N / 2; i++) {
        swap(arr[i], arr[N - i - 1]);
        swap(arr2[i], arr2[N - i - 1]);
        swap(arr3[i], arr3[N - i - 1]);
        swap(arr4[i], arr4[N - i - 1]);
    }
    std::cout << std::endl <<  "Reversed:" << std::endl;
    results = test_sorting(arr, arr2, arr3, arr4);
    for (auto i : results)
        std::cout << i.first << " -> " << i.second << std::endl;
    
    return 0;
}