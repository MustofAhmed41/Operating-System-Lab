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
    int burstTime2[numberOfProcess];
    int waitingTime[numberOfProcess];
    int arrivalTime[numberOfProcess];
    int servicedStatus[numberOfProcess];
    int processNumber[numberOfProcess];
    int arrivedProcesses[numberOfProcess];
    int priority[numberOfProcess];

    int totalTime = 0;
    for(int i = 0 ; i < numberOfProcess ; i++)
    {
        cin >> burstTime[i];
        totalTime += burstTime[i];
        burstTime2[i] = burstTime[i];
        servicedStatus[i] = 1;
        processNumber[i] = i;
        waitingTime[i] = 0;
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
    while(currentTime!=totalTime)
    {
        arrivalCount = 0;
        for(int i = 0; i < numberOfProcess; i++)
        {
            if(burstTime[i]<=0)
            {
                continue;
            }
            if(currentTime>=arrivalTime[i])
            {
                arrivedProcesses[arrivalCount] = i;
                arrivalCount++;
            }
        }
        //finding out the highest priority at the given moment
        int highestPriority = priority[arrivedProcesses[0]];
        int highestTrack = arrivedProcesses[0];
        for(int i = 0 ; i <arrivalCount;i++){
            if(highestPriority>priority[arrivedProcesses[i]]){
                highestPriority = priority[arrivedProcesses[i]];
                highestTrack = arrivedProcesses[i];
            }
        }
        //highestTrack has the process number of the highest priority at the given moment

        //found out the process with the highest priority at the given time
        burstTime[highestTrack]--;
        for(int i = 0 ; i < numberOfProcess; i++){
            if(burstTime[i]<=0){
                continue;
            }
            if(i==highestTrack){
                continue;
            }
            //checking if process arrived
            if(currentTime<arrivalTime[i]){
                continue;
            }
            //increasing waiting time for all other process
            waitingTime[i]++;
        }
        currentTime++;
    }

    double totalWaitingTime = 0;
    double totalTurnAroundTime = 0;

    for(int j=0; j < numberOfProcess; j++)
    {
        for(int i = 0; i < numberOfProcess; i++)
        {
            if(j==processNumber[i])
            {
                totalWaitingTime += waitingTime[i];
                showOutput(processNumber[i], waitingTime[i], waitingTime[i]+burstTime2[i]);
                totalTurnAroundTime += (waitingTime[i]+burstTime2[i]);
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
