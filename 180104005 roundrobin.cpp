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
    int timeQuantum;
    cout << "Enter Number of Process: ";
    cin >> numberOfProcess;
    cout << "Enter CPU times : " << endl;


    int CPUTime[numberOfProcess];
    int CPUTime2[numberOfProcess];
    int waitingTime[numberOfProcess];
    int arrivalTime[numberOfProcess];
    int processNumber[numberOfProcess];
    int serviceStatus[numberOfProcess];
    int waitingTimeArray[numberOfProcess][15];
    int waitingTimeTracker[numberOfProcess];

    int totalTime = 0;

    for(int i = 0 ; i < numberOfProcess ; i++)
    {
        cin >> CPUTime[i];
        CPUTime2[i] = CPUTime[i];
        processNumber[i] = i;
        totalTime += CPUTime[i];
        serviceStatus[i] = 1;
        waitingTime[i] = 0;
        waitingTimeTracker[i] = 0;
        for(int j=0;j<15;j++)
            waitingTimeArray[i][j] = 0;
    }

    cout << "Enter the arrival times : " << endl;

    for(int i = 0 ; i < numberOfProcess ; i++)
    {
        cin >> arrivalTime[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> timeQuantum;

    int currentTime = 0;

    queue <int> que;

    while(1){

        for(int i = 0 ; i < numberOfProcess; i++)
        {
            if(serviceStatus[i]==1)
            {
                if(currentTime>=arrivalTime[i])
                {

                    que.push(i);
                    serviceStatus[i] = 0;
                }
            }
        }

        int service = que.front();
        que.pop();

        waitingTimeArray[service][waitingTimeTracker[service]] = currentTime;
        waitingTimeTracker[service]++;


        if(CPUTime[service]<= timeQuantum){
            currentTime += CPUTime[service];
            CPUTime[service] = 0;
        }else{
            CPUTime[service] -= timeQuantum;
            currentTime += timeQuantum;
            for(int i = 0 ; i < numberOfProcess; i++){
                if(serviceStatus[i]==1){
                    if(currentTime>=arrivalTime[i]){
                        que.push(i);
                        serviceStatus[i] = 0;
                    }
                }
            }
            que.push(service);
        }


        if(currentTime==totalTime){
            break;
        }

    }

    cout << endl;
    for(int i =0;i< numberOfProcess;i++){
        for(int j=0; j<15;j++){
            cout << waitingTimeArray[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i =0 ; i < numberOfProcess;i++){
        cout << waitingTimeTracker[i] <<endl;
    }

    double totalWaitingTime = 0;
    for(int i =0;i< numberOfProcess;i++){
        int wait = 0;

        for(int j=0; j<waitingTimeTracker[i]-1;j++){
           wait += waitingTimeArray[i][j+1] - (waitingTimeArray[i][j]+timeQuantum);
        }
        wait += waitingTimeArray[i][0];
        wait -= arrivalTime[i];
        waitingTime[i] = wait;
        totalWaitingTime += wait;

    }

    double totalTurnAroundTime = 0;

    for(int i = 0 ; i < numberOfProcess; i++){
        totalTurnAroundTime += waitingTime[i]+CPUTime2[i];
        showOutput(i+1,waitingTime[i],waitingTime[i]+CPUTime2[i]);
    }

    cout << "Average Waiting Time : "<< totalWaitingTime/numberOfProcess << endl;
    cout << "Average Turnaround Time : "<< totalTurnAroundTime/numberOfProcess << endl;

    return 0;
}

/*
4
5 7 9 9
4 0 6 10
3

5
5 3 4 6 2
2 0 3 5 7

*/
