#include <bits/stdc++.h>

using namespace std;


void showOutput(int processNumber, int waitingTime, int turnAroundTime){
    cout << "Process " << processNumber << " : ";
    cout << "Waiting Time " << " : " << waitingTime << "\t";
    cout << "Turnaround Time " << " : " << turnAroundTime << endl;
}

int main()
{
    int numberOfProcess;
    cout << "Enter Number of Process: ";
    cin >> numberOfProcess;
    cout << "Enter CPU times : " << endl;

    int burstTime[numberOfProcess];
    int waitingTime[numberOfProcess];
    int arrivalTime[numberOfProcess];
    int servicedStatus[numberOfProcess];
    int processNumber[numberOfProcess];
    int arrivedProcesses[numberOfProcess];
    int priority[numberOfProcess];

    for(int i = 0 ; i < numberOfProcess ; i++)
    {
        cin >> burstTime[i];
        servicedStatus[i] = 1;
        processNumber[i] = i;
    }

    cout << "Enter the arrival times : " << endl;

    for(int i = 0 ; i < numberOfProcess ; i++)
    {
        cin >> arrivalTime[i];
    }

    for(int i = 0 ; i < numberOfProcess ; i++)
    {
        cin >> priority[i];
    }

    cout << endl;


    int currentTime = 0;
    int counter=0;
    int arrivalCount = 0;
    while(counter!=numberOfProcess)
    {
        arrivalCount = 0;
        for(int i = 0; i < numberOfProcess; i++)
        {
            if(servicedStatus[i]==0)
            {
                continue;
            }
            if(currentTime>=arrivalTime[i])
            {
                arrivedProcesses[arrivalCount] = i;
                arrivalCount++;
            }
        }

        int highestPriority = priority[arrivedProcesses[0]];
        int highestTrack = arrivedProcesses[0];
        for(int i = 0 ; i <arrivalCount;i++){ //i can start with 1 as well
            if(highestPriority>priority[arrivedProcesses[i]]){
                highestPriority = priority[arrivedProcesses[i]];
                highestTrack = arrivedProcesses[i];
            }
        }
        //highestT contains the process with highest priority at the given moment

        servicedStatus[highestTrack] = 0;
        waitingTime[highestTrack] = currentTime;
        currentTime += burstTime[highestTrack];
        counter++;
    }


    double totalWaitingTime = 0;
    double totalTurnAroundTime = 0;

    for(int j=0; j < numberOfProcess; j++)
    {
        for(int i = 0; i < numberOfProcess; i++)
        {
            if(j==processNumber[i])
            {
                waitingTime[i] = waitingTime[i] - arrivalTime[i];
                totalWaitingTime += waitingTime[i];

                showOutput(processNumber[i], waitingTime[i], waitingTime[i]+burstTime[i]);

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
5 7 9
4 0 2
0 2 1
*/





