
#include <bits/stdc++.h>

using namespace std;

void sorting(int arr[], int arr2[], int arr3[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swap(arr2[j], arr2[j+1]);
                swap(arr3[j], arr3[j+1]);
            }
        }
    }
}


int main()
{
    int numberOfProcess;
    cout << "Enter Number of Process: ";
    cin >> numberOfProcess;
    cout << "Enter burst/cpu time for " << numberOfProcess << " processes " << endl;

    int burstTime[numberOfProcess];
    int arrivalTime[numberOfProcess];
    int waitingTime[numberOfProcess];
    int processNumber[numberOfProcess];

    for(int i = 0 ; i < numberOfProcess ; i++)
    {
        cin >> burstTime[i];
        processNumber[i] = i+1;
    }

    for(int i = 0 ; i < numberOfProcess ; i++)
    {
        cin >> arrivalTime[i];
    }

    sorting(arrivalTime,burstTime,processNumber,numberOfProcess);

    waitingTime[0] = 0; // the first process will get serviced first so waiting time is 0 for this
    double totalWaitingTime = waitingTime[0]; // totalwaiting time is initialised with 0

    double totalTurnAroundTime = waitingTime[0]+burstTime[0]-arrivalTime[0];
    cout << "Waiting Time for process " << processNumber[0] << " is " << waitingTime[0] << "  Turn Around Time: " <<  (waitingTime[0]+burstTime[0]-arrivalTime[0]) << endl;
    for(int i = 1 ; i < numberOfProcess ; i++)
    {
        waitingTime[i] = waitingTime[i-1] + burstTime[i-1];
        //total waiting time of current process depends on the waiting time of previous process and its burst time
        cout << "Waiting Time for process " << processNumber[i] << " is " << waitingTime[i]-arrivalTime[i] << "  Turn Around Time: " <<  waitingTime[i]+burstTime[i]-arrivalTime[i] << endl;
        totalTurnAroundTime += waitingTime[i]+burstTime[i]-arrivalTime[i];
        totalWaitingTime += (waitingTime[i]-arrivalTime[i]);
    }

    cout<<fixed<<setprecision(2) << endl;
    double averageWaitingTime = totalWaitingTime/numberOfProcess;
    cout << ":::::::::OUTPUT::::::::::" << endl << endl;
    cout << "Average waiting Time: " <<  averageWaitingTime << endl;
    cout << "Average TurnAround Time: " << totalTurnAroundTime/numberOfProcess << endl;

    return 0;
}




/*
3
24 3 3
0 0 0

4
5 3 8 6
0 1 2 3


3
5 7 9
4 0 2
*/
