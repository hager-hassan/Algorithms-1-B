#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Priority_Queue{
private:
    vector<pair<int, int>> queue;

    // after insertion
    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (queue[index].second > queue[parent].second) // compare child with parent
            {
                swap(queue[index], queue[parent]);
                index = parent; // move to parent to make sure
            }
            else
                break;
        }
    }

    // after extraction
    void heapifyDown(int index)
    {
        int size = queue.size();
        while (true)
        {
            int left = 2 * index + 1 , right = 2 * index +2;
            int largest = index;

            if (left < size && queue[left].second > queue[largest].second)
            {
                largest = left;
            }

            if (right < size && queue[right].second > queue[largest].second)
            {
                largest = right;
            }

            if(largest == index)
                break;

            swap(queue[index], queue[largest]);
            index = largest; // update index location to make sure
        }
    }

public:
    void insert(int value, int priority)
    {
        queue.emplace_back(value, priority);
        heapifyUp(queue.size() - 1);
    }

    void deleteMax()
    {
        if(queue.empty())
        {
            cout << "QUEUE IS EMPTY." << '\n';
        }
        else
        {
            queue[0] = queue.back(); // move last element to root
            queue.pop_back();

            heapifyDown(0);
        }
    }

    int getMax()
    {
        if(queue.empty())
        {
            cout << "QUEUE IS EMPTY." << '\n';
            return 0;
        }
        else
        {
            return queue[0].first;
        }
    }

    void print()
    {
        if(!queue.empty())
        {
            for (const auto& element : queue)
            {
                cout << "(" << element.first << ", " << element.second << ")" << '\n';
            }
        }
    }

};


int main(){
    int optionNum = 100 , num = 0 , priority = 0;
    Priority_Queue pq;

    while (optionNum != 0)
    {
        cout << "Enter the number for the option you want: " << '\n'
             << "1-Insert element."                          << '\n'
             << "2-Delete max element."                      << '\n'
             << "3-Get max element."                         << '\n'
             << "4-Print elements."                          << '\n'
             << "Press 0 to exit the program."               << '\n';

        cin >> optionNum;

        switch (optionNum)
        {
            case 1:
            {
                cout << "Please enter the number and its priority:" << '\n';
                cin >> num >> priority;
                pq.insert(num , priority);
                continue;
            }
            case 2:
            {
                pq.deleteMax();
                continue;
            }
            case 3:
            {
                int max = pq.getMax();
                cout << "Max element is: " << max <<'\n';
                continue;
            }
            case 4:
            {
                pq.print();
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