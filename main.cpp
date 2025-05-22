#include <iostream>
#include <iomanip> //setw()
#include <cstdlib>
#include <ctime> 
#include "fenwiktree.h"

using namespace std;

int main() {
    srand(time(0));

    // table
    cout << left
        << setw(10) << "Size"
        << setw(15) << "Build(ms)"
        << setw(15) << "Sum(mics)"
        << setw(10) << "SumOpers"
        << setw(15) << "Range(mics)"
        << setw(10) << "RangeOpers" << endl;

    int sizes[] = { 10, 100, 1000, 10000 };

    for (int i = 0; i < 4; i++) {
        int size = sizes[i];

        // create a tree
        clock_t start = clock();
        FenwikTree ft(size);

        // create random nums
        for (int j = 0; j < size; j++) {
            ft.update(j, rand() % 1000 + 1);
        }
        double build_time = (clock() - start) * 1000.0 / CLOCKS_PER_SEC;

        // sum
        int test_index = size / 2;
        start = clock();
        int sum_result = ft.sum(test_index);
        double sum_time = (clock() - start) * 1000000.0 / CLOCKS_PER_SEC;
        int sum_ops = ft.getLastSumOp();

        // rangeSum
        int l = size / 4;
        int r = 3 * size / 4;
        start = clock();
        int range_result = ft.rangeSum(l, r);
        double range_time = (clock() - start) * 1000000.0 / CLOCKS_PER_SEC;
        int range_ops = ft.getLastRangeOp();

        // print results
        cout << left
            << setw(10) << size
            << setw(15) << fixed << setprecision(2) << build_time
            << setw(15) << setprecision(0) << sum_time
            << setw(10) << sum_ops
            << setw(15) << range_time
            << setw(10) << range_ops << endl;
    }

    return 0;
}