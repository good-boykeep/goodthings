#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
void NewFunction()
{
    SetConsoleOutputCP(65001);
}
void generateArray(int arr[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    NewFunction();
    const int SIZE = 10;
    int originalArray[SIZE];
    int tempArray[SIZE];
    generateArray(originalArray, SIZE);
    cout << "\n原始数列:";
    printArray(originalArray, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        tempArray[i] = originalArray[i];
    }
    bubbleSort(tempArray, SIZE);
    cout << "冒泡排序：";
    printArray(tempArray, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        tempArray[i] = originalArray[i];
    }
    selectionSort(tempArray, SIZE);
    cout << "选择排序：";
    printArray(tempArray, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        tempArray[i] = originalArray[i];
    }
    insertionSort(tempArray, SIZE);
    cout << "插入排序：";
    printArray(tempArray, SIZE);
    system("pause");
    return 0;
}