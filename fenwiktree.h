#ifndef FENWIKTREE_H
#define FENWIKTREE_H

#include <vector>

using namespace std;

class FenwikTree {
public:
    FenwikTree(int size);

    void update(int index, int x);  // ���������� ��������
    int sum(int index);             // ���������� �����
    int rangeSum(int l, int r);     // ����� �� �������

    // ������ ��� ��������� ���������� ��������
    int getLastUpdateOp();
    int getLastSumOp();
    int getLastRangeOp();

private:
    vector<int> tree;
    int size;
    int last_update_op;  // ��������
    int last_sum_op;
    int last_range_op;
};

#endif // FENWIKTREE_H