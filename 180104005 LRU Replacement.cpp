#include <bits/stdc++.h>

using namespace std;

int noOfPage;
int noOfReference;
int refs[200];
int page[200];
int pageTracker[200];
int pageSize;
int storeCounter;
int store[200][200];

void findReplacementNumber(int range)
{
    for(int i = 0 ; i < pageSize; i++)
    {
        for(int j = range-1 ; j >= 0 ; j--)
        {
            if(page[i]==refs[j])
            {
                pageTracker[i] = j;
                break;
            }
        }
    }
    return;
}

void storeNumber()
{
    for(int i = 0 ; i < pageSize; i++)
    {
        store[storeCounter][i] = page[i];
    }
    storeCounter++;
}

void printPage()
{

    for(int i = 0 ; i < pageSize; i++)
    {
        cout << page[i] << "  ";
    }
    cout << endl;
}

void output()
{
    for(int i = 0 ; i < noOfReference; i++)
    {
        cout << refs[i] << " ";
    }
    cout  << endl;
    cout  << endl;

    for(int i = 0 ; i < pageSize; i++)
    {
        for(int j = 0 ; j < storeCounter; j++)
        {
            cout << store[j][i] << " ";
        }
        cout << endl;
    }

}


int main()
{
    cout << "Enter No Of Page : ";
    cin >> noOfPage;
    cout << "Enter No Of Reference : ";
    cin >> noOfReference;
    cout << "Enter References : ";
    for(int i = 0 ; i < noOfReference; i++)
    {
        cin >> refs[i];
    }
    cout << "Enter Page Size : ";
    cin >> pageSize;

    for(int i = 0 ; i < pageSize; i++)
    {
        page[i] = refs[i];
        storeNumber();
    }
    cout << endl << endl;
    int pageFault = 3;
    // printPage();
    for(int i = pageSize; i < noOfReference; i++)
    {

        bool pageFaultCheck = true;
        for(int j = 0; j < pageSize; j++)
        {
            if(page[j]==refs[i])
            {
                pageFaultCheck = false;
                break;
            }
        }

        if(pageFaultCheck)
        {
            pageFault++;
            findReplacementNumber(i);
            int leastRecent = 1000;
            for(int k = 0; k < pageSize; k++)
            {
                if(pageTracker[k]<leastRecent)
                {
                    leastRecent = pageTracker[k];
                }
            }
            int repl = refs[leastRecent];
            for(int z = 0 ; z < pageSize; z++)
            {
                if(repl==page[z])
                {
                    page[z] = refs[i];
                    break;
                }
            }
        }
        // printPage();
        storeNumber();

    }

    output();
    cout << endl << "Total Page Faults : " << pageFault;

    return 0;
}


/*
8
22
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
3


*/
