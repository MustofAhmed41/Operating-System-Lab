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
    int waitingTime[numberOfProcess];
    int arrivalTime[numberOfProcess];
    int servicedStatus[numberOfProcess];
    int processNumber[numberOfProcess];

    for(int i = 0 ; i < numberOfProcess ; i++)
    {
        cin >> burstTime[i];
        servicedStatus[i] = 1;
        processNumber[i] = i+1;
    }

    for(int i = 0 ; i < numberOfProcess ; i++)
    {
        cin >> arrivalTime[i];
    }

    cout << endl;

    sorting(burstTime,arrivalTime,processNumber,numberOfProcess);

    double currentTime = 0.0;
    int counter=0;

    while(counter!=numberOfProcess)
    {
        for(int i = 0; i < numberOfProcess; i++)
        {
            if(servicedStatus[i]==0)
            {
                continue;
            }
            if(currentTime>=arrivalTime[i])
            {
                waitingTime[i] = currentTime;
                currentTime = currentTime + burstTime[i];
                servicedStatus[i] = 0;
                counter++;
                break;
            }
        }
    }

    double totalWaitingTime = 0;
    double totalCPUTime = 0;
    double totalTurnAroundTime = 0;

    for(int j=0; j < numberOfProcess; j++)
    {
        for(int i = 0; i < numberOfProcess; i++)
        {
            if(j+1==processNumber[i])
            {
                waitingTime[i] = waitingTime[i] - arrivalTime[i];
                totalWaitingTime += waitingTime[i];
                totalCPUTime += burstTime[i];
                cout << "Waiting Time for process " << processNumber[i] << " is " << waitingTime[i]
                     << "  Turn Around Time: " <<  (waitingTime[i]+burstTime[i]) << endl;
                totalTurnAroundTime += (waitingTime[i]+burstTime[i]);
                break;
            }
        }
    }

    cout<<fixed<<setprecision(2);
    cout << endl;
    cout << "Average waiting Time: " <<  totalWaitingTime/numberOfProcess << endl;
    cout << "Average Turn Around Time: " << totalTurnAroundTime/numberOfProcess << endl;

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

