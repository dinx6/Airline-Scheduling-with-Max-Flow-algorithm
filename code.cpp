#include <iostream>
#include <string.h>
using namespace std;

const int M=6,N=6;

bool bpm(bool graph[M][N], int u,bool seen[], int match[])
{
	for (int v = 0; v < N; v++)
	{
		if (graph[u][v] && !seen[v])
		{
			seen[v] = true;
            if (match[v] < 0 || bpm(graph, match[v],seen, match))
			{
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}
int maxbpm(bool graph[M][N])
{
	int match[N];
	memset(match, -1, sizeof(match));
	int result = 0;
	for (int u = 0; u < M; u++)
	{
		bool seen[N];
		memset(seen, 0, sizeof(seen));

		if (bpm(graph, u, seen, match))
			result++;
	}
	return result;
}

int main()
{
    bool graph[M][N];

    int arr[6]={1,2,3,4,5,6};
    //Flights
    float start_time[6]={8,14,10,9,14.05,11};
    //Starting time of the flights
    float end_time[6]={12,18,15,12.05,18,17};
    //Ending time of flights
    char source[6]={'A','B','C','D','B','E'};
    //Starting airport
    char dest[6]={'B','C','A','B','E','D'};
    //Destination airport
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
        if(source[j]==dest[i])
            {
                if(end_time[i]-start_time[j]>=0)
                    graph[i][j]=1;
                else
                    graph[i][j]=0;
            }
        else
            graph[i][j]=0;
        }
    }
    cout<<endl;
	cout << "Maximum number of flights required:"<< maxbpm(graph)<<endl;
	return 0;
}
