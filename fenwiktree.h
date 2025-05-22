#ifndef FENWIKTREE_H
#define FENWIKTREE_H

#include <vector>

using namespace std;

class FenwikTree {
public:
    FenwikTree(int size);

    void update(int index, int x);  // Обновление элемента
    int sum(int index);             // Префиксная сумма
    int rangeSum(int l, int r);     // Сумма на отрезке

    // Методы для получения количества операций
    int getLastUpdateOp();
    int getLastSumOp();
    int getLastRangeOp();

private:
    vector<int> tree;
    int size;
    int last_update_op;  // Счётчики
    int last_sum_op;
    int last_range_op;
};

#endif // FENWIKTREE_H