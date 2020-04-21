#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;

int partition(int *numbers, int left, int right)
{
    int pivot = numbers[right];
    int i = left, j = right;

    while (i <= j)
    {
        while (numbers[i] < pivot)
            i++;
        while (numbers[j] > pivot)
            j--;

        if (i <= j)
        {
            swap(numbers[j], numbers[i]);
            i++;
            j--;
        }
    }

    return j;
}

void sort(int *numbers, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(numbers, left, right);

        sort(numbers, left, pivot);
        sort(numbers, pivot + 1, right);
    }
}

void quickSort(int *numbers, int array_size)
{
    sort(numbers, 0, array_size - 1);
}

int main()
{
    int *brr;
    int n;

    fstream fin;
    fin.open("input.txt",ios::in);
    if (fin.is_open())
    {
        fin >> n;
        brr = new int[n];
        for (int i = 0; i < n; i++)
            fin >> brr[i];

        fin.close();
    }
    quickSort(brr, n);
    fstream fout;
    fout.open("output.txt",ios::out);
    for (int i = 0; i < n; i++)
        fout << brr[i] << " ";

    fout.close();
    delete[] brr;
    return 0;
}