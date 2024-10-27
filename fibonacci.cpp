#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// IMPLEMENT FIBONACCI SERIES USING RECURSION
int R_Fibonacci_Series(int num)
{
    if (num <= 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        return R_Fibonacci_Series(num - 1) + R_Fibonacci_Series(num - 2);
    }
}

//--------------------------------------------------------------------------------------------------

// IMPLEMENT FIBONACCI SERIES USING MATRIX
void multiply(int A[2][2], int B[2][2], int result[2][2]) // multiply two 2*2 matrices
{
    int temp[2][2];

    temp[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    temp[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    temp[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    temp[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];

    result[0][0] = temp[0][0];
    result[0][1] = temp[0][1];
    result[1][0] = temp[1][0];
    result[1][1] = temp[1][1];
}

void power(int matrix[2][2], int n)
{
    if (n <= 1) return; // base case

    int result[2][2] = {{1, 1},    // base matrix
                        {1, 0}};


    power(matrix, n / 2);

    multiply(matrix, matrix, matrix); // square the matrix

    if (n % 2 != 0)  // if n is odd
    {
        multiply(matrix, result, matrix);
    }
}
int M_Fibonacci_Series(int num)
{
    if (num == 0)
        return 0;

    int matrix[2][2] = {{1, 1},
                        {1, 0}};
    power(matrix, num - 1); // matrix to the (n-1) power

    return matrix[0][0]; // F(n)
}

//--------------------------------------------------------------------------------------------------

// IMPLEMENT FIBONACCI SERIES USING DYNAMIC PROGRAMMING
int D_Fibonacci_Series(int num);


int main() {
    int optionNum = 100 , fibNum = 0 , result = 0;

    while (optionNum != 0)
    {
        cout << "Enter the number for the option you want: "        << '\n'
             << "1-Fibonacci series using recursion."               << '\n'
             << "2-Fibonacci series using matrix multiplication."   << '\n'
             << "3-Fibonacci series using dynamic programming."     << '\n'
             << "Press 0 to exit the program."                       << '\n';

        cin >> optionNum;

        switch (optionNum)
        {
            case 1:
            {
                cout <<"Enter the number: " << '\n';
                cin >> fibNum;
                result = R_Fibonacci_Series(fibNum);
                cout << "The result is: " << result << '\n';
                continue;
            }
            case 2:
            {
                cout <<"Enter the number: " << '\n';
                cin >> fibNum;
                result = M_Fibonacci_Series(fibNum);
                cout << "The result is: " << result << '\n';
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
