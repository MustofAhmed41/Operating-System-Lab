#include <bits/stdc++.h>

using namespace std;

int Holes[100], Requests[100];
int h,r;
void printHR()
{
    for(int i = 0 ; i < h; i++)
    {
        cout << Holes[i] << " ";
    }
    cout << endl;
}

main()
{
    cout << "Enter number of holes : ";
    cin >> h;
    cout << "Enter number of requests : ";
    cin >> r;

    cout << "Enter Memory Hole values : ";
    for(int i = 0 ; i < h; i++)
    {
        cin >> Holes[i];
    }

    cout << "Enter Memory Requests values : ";
    for(int i = 0 ; i < r; i++)
    {
        cin >> Requests[i];
    }

    cout << endl << endl;
    cout << ":::::::::OUTPUT:::::::::::";
    cout << endl << endl;

    bool test;
    printHR();
    for(int i = 0 ; i < r; i++)
    {
        test = false;
        for(int j = 0 ; j < h; j++)
        {

            if(Requests[i]<=Holes[j])
            {
                Holes[j] = Holes[j] - Requests[i];
                printHR();
                test = true;
                break;
            }
        }
        if(!test)
        {
            cout << endl << "Cannot be Allocated : ";
            for(int k = i ; k < r; k++)
            {
                cout << Requests[k] << " ";
            }
            int sum = 0;
            for(int k = 0; k < h; k++)
            {
                sum += Holes[k];
            }
            cout << endl << "External Fragmentation : " << sum << endl;
            return 0;
        }
    }

    cout << endl << "All requests has received services" << endl;

    return 0;
}

/*
5
10
50 200 70 115 15
100 10 35 15 23 6 25 55 88 40
*/




