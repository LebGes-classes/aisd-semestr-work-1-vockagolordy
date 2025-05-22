#include "fenwiktree.h"

FenwikTree::FenwikTree(int size) :
    size(size),
    tree(size + 1, 0),
    last_update_op(0),
    last_sum_op(0),
    last_range_op(0) {}

void FenwikTree::update(int index, int x) {
    last_update_op = 0;
    index++;
    while (index <= size) {
        tree[index] += x;
        index += index & -index;
        last_update_op++;
    }
}

int FenwikTree::sum(int index) {
    last_sum_op = 0;
    index++;
    int result = 0;
    while (index > 0) {
        result += tree[index];
        index -= index & -index;
        last_sum_op++;
    }
    return result;
}

int FenwikTree::rangeSum(int l, int r) {
    last_range_op = 0;
    int sum_r = sum(r);
    int sum_l_1 = sum(l - 1);
    last_range_op = last_sum_op;  // Сумма операций двух вызовов sum()
    return sum_r - sum_l_1;
}

int FenwikTree::getLastUpdateOp() { return last_update_op; }
int FenwikTree::getLastSumOp() { return last_sum_op; }
int FenwikTree::getLastRangeOp() { return last_range_op; }