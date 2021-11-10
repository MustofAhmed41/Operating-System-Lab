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

int findWorstHole(int req){
    int i;
    int diff, diff_i;
    bool check = false;
    for( i = 0 ; i < h; i++){
        if(Holes[i]>= req){
            diff = Holes[i] - req;
            diff_i = i;
            check = true;
            break;
        }
    }
    if(!check){
        return -1;
    }

    for( ; i < h; i++){
        if( (Holes[i]-req) > diff ){
            diff = Holes[i] - req;
            diff_i = i;
        }
    }

    return diff_i;
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

    printHR();
    for(int i = 0 ; i < r; i++)
    {
        int worst = findWorstHole(Requests[i]);
        if(worst == -1){
            cout << "Cannot Allocate : ";
            for(int j = i; j < r ; j++){
                cout << Requests[j] << " ";
            }
            int sum = 0;
            for(int k = 0; k < h; k++)
            {
                sum += Holes[k];
            }
            cout << endl << "External Fragmentation : " << sum << endl;
            return 0;
        }
        Holes[worst] = Holes[worst] - Requests[i];
        printHR();
    }

    cout << endl << "No External Fragmentation" << endl;

    return 0;
}

/*
5
10
50 200 70 115 15
100 10 35 15 23 6 25 55 88 40
*/




