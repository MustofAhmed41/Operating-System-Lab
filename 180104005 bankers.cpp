#include <bits/stdc++.h>

using namespace std;

int checkService(int status[],
                 int process)
{
    for(int i = 0; i< process; i++)
    {
        if(status[i]==1)
        {
            return 1;
        }
    }
    return 0;
}


int main()
{
    int numberOfProcess;
    int numberOfResource;
    cout << "Enter No. of Process : ";
    cin >> numberOfProcess;
    cout << "Enter No. of resources : ";
    cin >> numberOfResource;

    int allocated[numberOfProcess][numberOfResource];
    int maxNeed[numberOfProcess][numberOfResource];
    int need[numberOfProcess][numberOfResource];
    int resource[numberOfResource];

    int checkStatus[numberOfProcess];
    cout << endl;
    for(int i = 0 ; i < numberOfProcess; i++)
    {
        cout << endl << "Process : " << i+1 << endl;
        for(int j=0; j < numberOfResource; j++)
        {
            cout << "Maximum Value for Resource " << j+1 << " : " ;
            cin >> maxNeed[i][j];
        }
        for(int j=0; j < numberOfResource; j++)
        {
            cout << "Maximum Value for Resource " << j+1 << " : " ;
            cin >> allocated[i][j];
        }
    }

    for(int j=0; j < numberOfResource; j++)
    {
        cin >> resource[j];
    }


    for( int i = 0 ; i < numberOfProcess; i++)
    {
        for( int j = 0; j < numberOfResource; j++)
        {
            resource[j] -= allocated[i][j];
        }
        checkStatus[i] = 1;
    }

//    for(int i=0; i<numberOfResource;i++){
//        cout << resource[i] << " ";
//    }

    for(int i = 0 ; i < numberOfProcess; i++)
    {
        for(int j=0; j < numberOfResource; j++)
        {
            need[i][j] = maxNeed[i][j] - allocated[i][j];
            // cout << need[i][j] << " ";
        }
        //cout << endl;
    }
    int counter = 0;

    while(counter!=numberOfProcess)
    {
        int serviceProcess = -1;
        for(int i = 0 ; i < numberOfProcess; i++)
        {
            bool check = true;
            for(int j = 0 ; j < numberOfResource; j++)
            {
                if(need[i][j]>resource[j])
                {
                    check=false;
                }
            }
            if(check && checkStatus[i]==1)
            {
                serviceProcess = i;
                break;
            }
        }

        if(serviceProcess==-1){
            cout << "Deadlock Detected";
            break;
        }
        counter++;
        checkStatus[serviceProcess] = 0;
        cout << serviceProcess+1 << " ";
        for(int i = 0; i<numberOfResource; i++)
        {
            resource[i] += allocated[serviceProcess][i];
        }

    }



    return 0;
}


/*
4 3
3 2 2
1 0 0
6 1 3
5 1 1
3 1 4
2 1 1
4 2 2
0 0 2
9 3 6

5 3
7 5 3
0 1 0
3 2 2
2 0 0
9 0 2
3 0 2
4 2 2
2 1 1
5 3 3
0 0 2
10 5 7

*/

