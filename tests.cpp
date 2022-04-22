#include <gtest/gtest.h>
#include <fstream>
#include <iostream>

template<typename T, typename Comparator = std::less<T>>
int partition(T *arr, int l, int r, Comparator cmp = Comparator()) {
    int pivot_pos = (r > l) ? std::rand() % (r - l) + l : r;
    if (r != pivot_pos) {
        std::swap(arr[r], arr[pivot_pos]);
    }

    int i = l, j = l;
    while (j < r) {
        if (cmp(arr[r], arr[j])) {
            ++j;
        } else {
            std::swap(arr[i++], arr[j++]);
        }
    }

    std::swap(arr[i], arr[r]);
    return i;
}

template<typename T, typename Comparator = std::less<T>>
T k_stat(T *arr, int k, int l, int r, Comparator cmp = Comparator()) {
    k = (k / 100.0) * (r + 1);
    int pivot_pos = partition(arr, l, r, cmp);

    while (pivot_pos != k) {
        if (pivot_pos > k) {
            r = pivot_pos - 1;
        }
        if (pivot_pos < k) {
            l = pivot_pos + 1;
        }
        pivot_pos = partition(arr, l, r, cmp);
    }
    return arr[pivot_pos];
}


TEST(Taks, First) {
    std::stringstream input, output;
    std::ifstream in("test1.txt", std::ifstream::in);

    int n = 0; 
    in >> n;
    int *arr = new int[n]{0};
    for (size_t i = 0; i < n; ++i) {
        in >> arr[i];
    }

    EXPECT_EQ(10001, k_stat(arr, 10, 0, n - 1));
    EXPECT_EQ(50001, k_stat(arr, 50, 0, n - 1));
    EXPECT_EQ(90001, k_stat(arr, 90, 0, n - 1));

    delete[] arr;

}

TEST(Taks, Second) {
    std::stringstream input, output;
    std::ifstream in("test2.txt", std::ifstream::in);

    int n = 0; 
    in >> n;
    int *arr = new int[n]{0};
    for (size_t i = 0; i < n; ++i) {
        in >> arr[i];
    }

    EXPECT_EQ(2, k_stat(arr, 10, 0, n - 1));
    EXPECT_EQ(6, k_stat(arr, 50, 0, n - 1));
    EXPECT_EQ(10, k_stat(arr, 90, 0, n - 1));

    delete[] arr;

}