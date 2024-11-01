
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// IMPLEMENT THE BINARY SEARCH ITERATIVELY
template <class t>
int I_Binary_Search(t arr[], int low, int high, t key)
{
    while (low <= high)
    {
        int middle = (low + high) / 2;

        if (arr[middle] == key)
        {
            return middle;  // Return the index of the found key
        }
        else if (arr[middle] > key)
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }

    return -1; // Return -1 if the key is not found
}

//--------------------------------------------------------------------------------------------------

// IMPLEMENT THE SEQUENTIAL SEARCH ITERATIVELY
template <class t>
int I_Sequential_Search(t arr[] , int size , t key)
{
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

//--------------------------------------------------------------------------------------------------

// IMPLEMENT THE BINARY SEARCH RECURSIVELY
template <class t>
int R_Binary_Search(t arr[] , int low , int high , t key)
{
    if(high >= low)
    {
        int middle =  (low + high)/2;

        if(arr[middle] == key)
        {
            return middle;
        }

        if(arr[middle] > key)
        {
            return R_Binary_Search(arr , low , middle-1 , key);
        }

        return R_Binary_Search(arr , middle+1 , high , key);
    }
    return -1;
}

//--------------------------------------------------------------------------------------------------

// IMPLEMENT THE SEQUENTIAL SEARCH RECURSIVELY
template <class t>
int R_Sequential_Search(t arr[] , int size , int index , t key)
{
    if (index >= size)
    {
        return -1; //not found
    }

    if (arr[index] == key)
    {
        return index;
    }

    // Recursive call with the next index
    return R_Sequential_Search(arr, size, index+1, key);
}


int main() {
    int optionNum = 100;
    int sortedArr[10] = {-8, 0, 1, 4, 8, 10, 44, 49, 50, 60};
    int unsortedArr[10] = {45 , 7 ,0, -3 ,9 ,5 ,77 ,100 , 1 ,4};
    int arrSize = 10, key = 0;

    while (optionNum != 0)
    {
        cout << "Enter the number for the option you want: "      << '\n'
             << "1-Fibonacci series using recursion."             << '\n'
             << "2-Fibonacci series using matrix multiplication." << '\n'
             << "3-Fibonacci series using dynamic programming."   << '\n'
             << "4-Sequential Search."                            << '\n'
             << "5-Recursive Sequential Search."                  << '\n'
             << "6-Binary Search."                                << '\n'
             << "7-Recursive Binary Search."                      << '\n'
             << "8-Heap."                                         << '\n'
             << "9-Priority Queue."                               << '\n'
             << "10-Heap Sort."                                   << '\n'
             << "Press 0 to exit the program"                     << '\n';

        cin >> optionNum;

        switch (optionNum)
        {
            case 4:
            {
                cout << "Enter the key: " << '\n';
                cin >> key;
                int result = I_Sequential_Search(unsortedArr , arrSize , key);
                if (result != -1)
                {
                    cout << "Key found at index: " << result << '\n';
                }
                else
                {
                    cout << "Key not found." << '\n';
                }
                continue;
            }
            case 5:
            {
                cout << "Enter the key: " << '\n';
                cin >> key;
                int result = R_Sequential_Search(unsortedArr , arrSize , 0 , key);
                if (result != -1)
                {
                    cout << "Key found at index: " << result << '\n';
                }
                else
                {
                    cout << "Key not found." << '\n';
                }
                continue;
            }
            case 6:
            {
                cout << "Enter the key: " << '\n';
                cin >> key;
                int result = I_Binary_Search(sortedArr , 0 , arrSize-1 , key);
                if (result != -1)
                {
                    cout << "Key found at index: " << result << '\n';
                }
                else
                {
                    cout << "Key not found." << '\n';
                }
                continue;
            }
            case 7:
            {
                cout << "Enter the key: " << '\n';
                cin >> key;
                int result = R_Binary_Search(sortedArr , 0 , arrSize-1 , key);
                if (result != -1)
                {
                    cout << "Key found at index: " << result << '\n';
                }
                else
                {
                    cout << "Key not found." << '\n';
                }
                continue;
            }
            case 0:
                cout << "EXITING PROGRAM..." << '\n';
                break;
            default:
                cout << "INVALID OPTION :(" << '\n';
                continue;
        }
    }

    return 0;
}
