#include <bits/stdc++.h>

using namespace std;

int graph[200][200], isVisited[200];
int top=-1;
int n,e;
int dealockCounter=1;
void inputGraph(int n, int e)
{
    int source, destination;
    for(int i=0;i<e;i++)
    {
        cin >> source;
        cin >> destination;
        graph[source][destination]=1;
    }

}

void printGraph(int n)
{
    printf("The Input Graph is :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf(" %d ",graph[i][j]);
        }
        printf("\n");
    }
}

void printDetectedGraph(int arr[], int i , int j){
    cout << endl;
    cout  << "Detected Cycle " << dealockCounter++ << " : ";
    for(; i <= j; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
    return;
}

void detectCycle(int arr[], int n){

    if(n<3){
        return;
    }
    // 6 7 8 9 10 11
    //know already that  6-->7 , 7-->8 ....etc
    //checking 11 --> 9, 11 -->8, 11 -->7, 11-->6
    //checking 10 --> 8, 10 -->7, 10 -->6
    for(int i = 2 ; i < n; i++){
        for(int j = 0; j < i-1 ;j++ ){
            if(graph[arr[i]][arr[j]]==1){
                printDetectedGraph(arr,j,i);
            }
        }
    }

}

void dfs(int source)
{
    int ary[100];
    int aryCounter=0;
    int arr[100];
    int sizeOfArr = 0;
    int i, temp;
    stack <int> stk;
    stk.push(source);
    isVisited[source]=1;

    int counter = 0;
    while(1)
    {
        temp = stk.top();
        stk.pop();
        counter++;
        ary[aryCounter++] = temp; //dfs traversal
        arr[sizeOfArr++] = temp; // cycle
        for(i=0;i<n;++i)
        {
            if(graph[temp][i]==1 && isVisited[i]==0)
            {
                stk.push(i);
                isVisited[i]=1;
            }
        }

        if(counter==n)
            break;

        if(stk.size()==0){
            detectCycle(arr,sizeOfArr);
            sizeOfArr = 0;
            for(int i = n-1 ; i >= 0 ; i--){
                if(isVisited[i]==0){
                    stk.push(i);
                    isVisited[i] = 1;
                    break;
                }
            }
        }
    }

    cout << endl;
    cout << "The traversed graph using DFS is : ";
    for(int i = 0 ; i < aryCounter; i++){
        cout << ary[i] << " ";
    }
    printf("\n");
}

int main()
{
    printf("Enter no of Node: ");
    cin >> n;
    printf("Enter no of Edge: ");
    cin >> e;

    inputGraph(n,e);

    //printGraph(n);

    dfs(0);

    return 0;
}

/*

13
13
0 1
1 2
5 2
4 3
3 2
6 2
6 7
7 8
8 9
9 10
10 11
11 6
12 7


14
15
0 1
1 2
5 2
4 3
3 2
6 2
6 7
7 8
8 9
9 10
10 11
11 6
12 7
2 13
13 0


15
17
0 1
1 2
5 2
4 3
3 2
6 2
6 7
7 8
8 9
9 10
10 11
11 6
12 7
8 13
13 12
2 14
14 0


*/
