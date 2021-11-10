#include <bits/stdc++.h>

using namespace std;


void sorting(int arr[], int arr2[], int arr3[],int arr4[], int n)
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
                swap(arr4[j], arr4[j+1]);
            }

        }
    }
}

void showOutput(int processNumber, int waitingTime, int turnAroundTime){
    cout << "Process " << processNumber << " : ";
    cout << "Waiting Time " << " : " << waitingTime << "\t";
    cout << "Turnaround Time " << " : " << turnAroundTime << endl;
}


int main()
{
    int numberOfProcess;

    cout << "Enter the number of process: ";
    cin >> numberOfProcess;
    cout << endl;
    cout << "Enter the CPU times : " << endl;


    int CPUTime[numberOfProcess];
    int CPUTime2[numberOfProcess];
    int waitingTime[numberOfProcess];
    int arrivalTime[numberOfProcess];
    int processNumber[numberOfProcess];
    int turnAroundTime[numberOfProcess];
    int totalTime = 0;

    for(int i = 0 ; i < numberOfProcess ; i++)
    {
        cin >> CPUTime[i];
        CPUTime2[i] = CPUTime[i];
        processNumber[i] = i+1;
        totalTime += CPUTime[i];
        waitingTime[i] = 0;
    }

    cout << "Enter the arrival times : " << endl;

    for(int i = 0 ; i < numberOfProcess ; i++)
    {
        cin >> arrivalTime[i];
    }

    sorting(CPUTime,arrivalTime,processNumber,CPUTime2,numberOfProcess);

    int currentTime = 0;
    int counter=0;
    //cout << totalTime << endl;

    while(1)
    {
        for(int i=0; i < numberOfProcess; i++)
        {
            if(currentTime>=arrivalTime[i])
            {
                if(CPUTime[i]>0)
                {
                    //giving service to process i
                    CPUTime[i]--;
                    currentTime++;
                    sorting(CPUTime,arrivalTime,processNumber,CPUTime2,numberOfProcess);
                   // cout << processNumber[i] <<  " " << currentTime <<endl;
                    for( int j=0 ; j < numberOfProcess; j++)
                    {
                        //increasing waiting time for all other processes
                        if(i==j)
                            continue;

                        //checking if that process j requires service or not
                        //or else we wont increase its waiting time
                        if(CPUTime[j]==0)
                            continue;


                        //also check if process has arrived or not
//                        if(currentTime<arrivalTime[i]){
//                            continue;
//                        }

                        waitingTime[j]++;
                    }
                    break;
                }
            }
        }
        if(currentTime == totalTime)
            break;
    }
    cout << endl;
    double totalWaitingTime = 0;
    double totalTurnAroundTime = 0;

    for(int j=0; j < numberOfProcess ;j++){

        for(int i = 0 ; i < numberOfProcess ; i++)
        {
            if(j+1==processNumber[i]){
                waitingTime[i] = waitingTime[i]-arrivalTime[i];
                totalWaitingTime += waitingTime[i];
                turnAroundTime[i] = waitingTime[i]+CPUTime2[i];
                totalTurnAroundTime += turnAroundTime[i];
                showOutput(processNumber[i],waitingTime[i], turnAroundTime[i] );
                break;
            }
        }

    }

    cout<<fixed<<setprecision(2);
    double averageWaitingTime = totalWaitingTime/numberOfProcess;
    double averageTurnAroundTime = totalTurnAroundTime/numberOfProcess;
    cout << endl;
    cout << "Average waiting Time: " <<  averageWaitingTime << endl;
    cout << "Average Turnaround Time: " << averageTurnAroundTime << endl;


    return 0;
}


/*
4
8 4 9 5
0 1 2 3

3
7 3 4
0 1 3


3
5 7 9
4 0 2
*/

