#include "heapSort.hh"


void hSortAsc(std::vector<int> &input_arr, int begin, int last)
{
    std::vector<int> arr;

    for(int i = begin; i <= last; i++){
        arr.push_back(input_arr[i]);
    }
    int n = arr.size();

    for(int i = n/2-1; i >= 0; i--){
        makeMaxHeapAsc(arr, n, i);
    }
    
    for(int i = n-1; i>0; i--)
    {
        swap(arr, 0, i);
        makeMaxHeapAsc(arr, --n, 0);
    }

    for(int i = begin; i <= last; i++){
        input_arr[i] = arr[i-begin];
    }

}


void makeMaxHeapAsc(std::vector<int> &arr, int size, int parent_index)
{
    int max_index = parent_index;
    int l_child = parent_index*2 + 1;
    int r_child = parent_index*2 + 2;

    if(l_child < size && arr[l_child] > arr[max_index]){
        max_index = l_child;
    }
    if(r_child < size && arr[r_child] > arr[max_index]){
        max_index = r_child;
    }
    if(max_index != parent_index)
    {
        swap(arr, max_index, parent_index);
        makeMaxHeapAsc(arr, size, max_index);
    }

}


void hSortDesc(std::vector<int> &input_arr, int begin, int last)
{
    std::vector<int> arr;

    for(int i = begin; i <= last; i++){
        arr.push_back(input_arr[i]);
    }

    int n = arr.size();

    for(int i = n/2-1; i >= 0; i--){
        makeMaxHeapDesc(arr, n, i);
    }
    
    for(int i = n-1; i>0; i--)
    {
        swap(arr, 0, i);
        makeMaxHeapDesc(arr, --n, 0);
    }

    for(int i = begin; i <= last; i++){
        input_arr[i] = arr[i-begin];
    }
}


void makeMaxHeapDesc(std::vector<int> &arr, int size, int parent_index)
{
    int max_index = parent_index;
    int l_child = parent_index*2 + 1;
    int r_child = parent_index*2 + 2;

    if(l_child < size && arr[l_child] < arr[max_index]){
        max_index = l_child;
    }
    if(r_child < size && arr[r_child] < arr[max_index]){
        max_index = r_child;
    }
    if(max_index != parent_index)
    {
        swap(arr, max_index, parent_index);
        makeMaxHeapDesc(arr, size, max_index);
    }

}