#include <iostream>
using namespace std;

int Partition(int data[], int length, int start, int end)
{
    if (data == NULL || length <= 0 || start < 0 || end >= length)
        throw new exception("Invalid Parameters");

    int index = RandomInRange(start, end);
    swap(&data[index], &data[end]);

    int small = start - 1;
    for (index = start; index < end; index++){
        if (data[index] < data[end]){
            ++small;
            if (small != index)
                swap(&data[index], &data[small]);
        }
    }
    small++;
    swap(&data[small], &data[end]);
    return small;
}

void QuickSort(int data[], int length, int start, int end)
{
    if (start == end)
        return;

    int index = Partition(data, length, start, end);
    if (index > start)
        QuickSort(data, length, start, index - 1);
    if (index < end)
        QuickSort(data, length, index + 1, end);
}

//======= another one, better to understand
void quicksort(int left, int right, vector<int>& arr)
{
    int i, j, base, tmp;
    i = left;
    j = right;
    base = arr[left];
    tmp = 0;
    while (i < j){
        while (i < j && arr[j] >= base)
            j--;
        while (i < j && arr[i] <= base)
            i++;
        if (i < j){
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }
    arr[left] = arr[i];
    arr[i] = base;

    quicksort(left, i - 1, arr);
    quicksort(i + 1, right, arr)
}