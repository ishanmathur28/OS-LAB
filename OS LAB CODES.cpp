1.	First Come First Serve
2.	#include<iostream>
3.	using namespace std;
4.	class process
5.	{
6.	    public:
7.	    int pid;
8.	    int at;
9.	    int bt;
10.	    int st;
11.	    int rt;
12.	    int tat;
13.	    int wt;
14.	    int et;
15.	};
16.	int main()
17.	{
18.	    int n;
19.	    cout<<"Enter number of processes: "<<endl;
20.	    cin>>n;
21.	
22.	    process p[n];
23.	    bool visited[n];
24.	    int processes_completed = 0;
25.	    float avg_tat=0;
26.	    float avg_wt=0;
27.	    int curr_time = 0;
28.	
29.	    for(int i=0; i<n; i++)
30.	    {
31.	        cout<<"Enter arrival time for "<<i+1<<" process: "<<endl;
32.	        cin>>p[i].at;
33.	        cout<<"Enter burst time for "<<i+1<<" process: "<<endl;
34.	        cin>>p[i].bt;
35.	        p[i].pid = i+1;
36.	    }
37.	
38.	    while(processes_completed != n)
39.	    {
40.	        int index = -1;
41.	        int min_at = INT_MAX;
42.	
43.	        for(int i=0; i<n; i++)
44.	        {
45.	            if(p[i].at <= curr_time && !visited[i])
46.	            {
47.	                if(p[i].at < min_at)
48.	                {
49.	                    index = i;
50.	                    min_at = p[i].at;
51.	                }
52.	            }    
53.	        }
54.	
55.	        if(index != -1)
56.	        {
57.	            p[index].st = curr_time;
58.	            p[index].et = p[index].st + p[index].bt;
59.	            p[index].tat = p[index].et - p[index].at;
60.	            p[index].wt = p[index].tat - p[index].bt;
61.	            p[index].rt = p[index].st - p[index].at;
62.	
63.	            avg_tat += p[index].tat;
64.	            avg_wt += p[index].wt;
65.	            
66.	            curr_time += p[index].bt;
67.	            visited[index] = 1;
68.	            processes_completed++;
69.	        }
70.	        else
71.	        {
72.	            curr_time++;
73.	        }
74.	    }
75.	
76.	    cout<<endl<<endl;
77.	
78.	    cout<<"PID\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"ET\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;
79.	
80.	    for(int i=0; i<n; i++)
81.	    {
82.	        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].et<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
83.	    }
84.	
85.	    cout<<endl<<endl;
86.	
87.	    cout<<"Average Turnaround Time is : "<<(float)avg_tat/n<<endl;
88.	    cout<<"Average Waiting Time is : "<<(float)avg_wt/n<<endl;
89.	
90.	return 0;
91.	}
92.	
93.	//5 2 6 5 2 1 8 0 3 4 4

2. Shortest Job First
#include<iostream>
using namespace std;

class process
{
    public:
    int pid;
    int at;
    int bt;
    int rt;
    int et;
    int tat;
    int wt;
    int st;
};

int main()
{
    cout<<"Enter the number of processes: "<<endl;
    int n;
    cin>>n;

    float total_tat = 0;
    float total_wt = 0;

    process p[n];
    bool visited[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Enter arrival time for "<<i+1<<" process: "<<endl;
        cin>>p[i].at;
        cout<<"Enter burst time for "<<i+1<<" process: "<<endl;
        cin>>p[i].bt;
        p[i].pid = i+1;
    }

    int curr_time = 0;
    int process_completed = 0;

    while(process_completed != n)
    {
        int index = -1;
        int min_bt = INT_MAX;

        for(int i=0; i<n; i++)
        {
            if(p[i].at <= curr_time && visited[i] == 0)
            {
                if(p[i].bt < min_bt)
                {
                    index = i;
                    min_bt = p[i].bt;
                }
                if(p[i].bt == min_bt)
                {
                    if(p[i].at < p[index].at)
                    {
                        index = i;
                        min_bt = p[i].bt;
                    }
                }
            }
        }

        if(index != -1)
        {
            p[index].st = curr_time;
            p[index].et = p[index].st + p[index].bt;
            p[index].tat = p[index].et - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].rt = p[index].st - p[index].at;

            total_tat += p[index].tat;
            total_wt += p[index].wt;

            visited[index] = 1;
            process_completed++;
            curr_time += p[index].bt;
        }
        else
        {
            curr_time++;
        }
    }

    cout<<endl<<endl;

    cout<<"PID\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"ET\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].et<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }

    cout<<endl<<endl;

    cout<<"Average Turnaround Time is : "<<(float)total_tat/n<<endl;
    cout<<"Average Waiting Time is : "<<(float)total_wt/n<<endl;

return 0;
}

3. Shortest Remaining Time First
#include<iostream>
using namespace std;
class process
{
    public:
    int pid;
    int at;
    int bt;
    int et;
    int st;
    int rt;
    int tat;
    int wt;
};

int main()
{
    cout<<"Enter number of processes: "<<endl;
    int n;
    cin>>n;

    process p[n];
    float avg_tat=0;
    float avg_wt =0;

    int process_completed = 0;
    int curr_time = 0;
    bool visited[n];
    int remaining_bt[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Enter the arrival time for "<<i+1<<" process: "<<endl;
        cin>>p[i].at;
        cout<<"Enter the burst time for "<<i+1<<" process: "<<endl;
        cin>>p[i].bt;

        remaining_bt[i] = p[i].bt;
        p[i].pid = i+1;
    }

    while(process_completed != n)
    {
        int index = -1;
        int min_bt = INT_MAX;

        for(int i=0; i<n; i++)
        {
            if(p[i].at <= curr_time && !visited[i])
            {
                if(remaining_bt[i] < min_bt)
                {
                    index = i;
                    min_bt = p[index].bt;
                }
                if(remaining_bt[i] == min_bt)
                {
                    if(p[index].at < p[i].at)
                    {
                        index = i;
                        min_bt = p[index].bt;
                    }
                }
            }
        }


        if(index != -1)
        {
            if(remaining_bt[index] == p[index].bt )
            {
                p[index].st = curr_time;
            }

            remaining_bt[index] -= 1;
            curr_time++;

            if(remaining_bt[index] == 0)
            {
                p[index].et = curr_time;
                p[index].tat = p[index].et - p[index].at;
                p[index].wt = p[index].tat - p[index].bt;
                p[index].rt = p[index].st - p[index].at;

                process_completed++;
                visited[index] = 1;

                avg_tat += p[index].tat;
                avg_wt += p[index].wt;
            }
        }
        else
        {
            curr_time ++;
        }
    }

    cout<<endl<<endl;

    cout<<"PID\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"ET\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].et<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }

    cout<<endl<<endl;

    cout<<"Average Turnaround Time is : "<<(float)avg_tat/n<<endl;
    cout<<"Average Waiting Time is : "<<(float)avg_wt/n<<endl;

return 0;
}


4. Round Robin 
#include<iostream>
#include<queue>
using namespace std;

class process
{
    public:
    int at;
    int bt; 
    int rt;
    int st;
    int tat;
    int wt;
    int et;
    int pid;
};

bool compare(process p1, process p2)
{   
    return p1.at < p2.at;
}
bool compare2(process p1, process p2)
{
    return p1.pid < p2.pid;
}

int main()
{

    cout<<"Enter number of processes: "<<endl;
    int n;
    int tq;
    cin>>n;
    cout<<"Enter time quanta: "<<endl;
    cin>>tq;

    process p[n];
    int remaining_bt[n];
    bool visited[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Enter arrival time of "<<i+1<<" process: "<<endl;
        cin>>p[i].at;
        cout<<"Enter burst time of "<<i+1<<" process: "<<endl;
        cin>>p[i].bt;
        p[i].pid = i+1;
        remaining_bt[i] = p[i].bt;
    }

    sort(p, p+n, compare);

    queue<int> q;
    q.push(0);
    int curr_time = 0;
    int process_completed = 0;
    visited[0] = true;
    int index;
    float avg_tat = 0;
    float avg_wt = 0;

    while(process_completed != n)
    {
        index = q.front();
        q.pop();

        //agar process pehli baar aa rhi h 
        if(remaining_bt[index] == p[index].bt)
        {
            p[index].st = max(curr_time, p[index].at);
            curr_time = p[index].st;
        }

        if(remaining_bt[index] - tq > 0)
        {
            remaining_bt[index] -= tq;
            curr_time += tq;
        }
        else
        {
            curr_time += remaining_bt[index];
            remaining_bt[index] = 0;
            process_completed++;

            p[index].et = curr_time;
            p[index].tat = p[index].et - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].rt = p[index].st - p[index].at;

            avg_tat += p[index].tat;
            avg_wt += p[index].wt;
        }

        for(int i=0; i<n; i++)
        {
            if(remaining_bt[i] > 0 && p[i].at <= curr_time && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }

        if(remaining_bt[index] > 0)
        {
            q.push(index);
        }

        if(q.empty())
        {
            for(int i= 0; i<n; i++)
            {
                if(remaining_bt[i] > 0) 
                {
                    q.push(i);
                    visited[i] = true;
                    break;
                }
            }
        }
    }

    sort(p, p+n, compare2);

    cout<<endl<<endl;

    cout<<"PID\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"ET\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].et<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }

    cout<<endl<<endl;

    cout<<"Average Turnaround Time is : "<<avg_tat/n<<endl;
    cout<<"Average Waiting Time is : "<<avg_wt/n<<endl;

return 0;
}


5. Non-Preemptive Priority Scheduling
#include<iostream>
using namespace std;

class process
{
    public:
    int pid;
    int at;
    int bt;
    int rt;
    int et;
    int tat;
    int wt;
    int st;
    int priority;
};

int main()
{
    cout<<"Enter the number of processes: "<<endl;
    int n;
    cin>>n;

    float total_tat = 0;
    float total_wt = 0;

    process p[n];
    bool visited[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Enter arrival time for "<<i+1<<" process: "<<endl;
        cin>>p[i].at;
        cout<<"Enter burst time for "<<i+1<<" process: "<<endl;
        cin>>p[i].bt;
        cout<<"Enter priority "<<i+1<<" process: "<<endl;
        cin>>p[i].priority;

        p[i].pid = i+1;
    }

    int curr_time = 0;
    int process_completed = 0;

    while(process_completed != n)
    {
        int index = -1;
        int max_priority= -1;

        for(int i=0; i<n; i++)
        {
            if(p[i].at <= curr_time && !visited[i])
            {
                if(p[i].priority > max_priority)
                {
                    index = i;
                    max_priority = p[i].priority;
                }
                if(p[i].priority == max_priority)
                {
                    if(p[i].at < p[index].at)
                    {
                        index = i;
                        max_priority = p[i].priority;
                    }
                }
            }
        }

        if(index != -1)
        {
            p[index].st = curr_time;
            p[index].et = p[index].st + p[index].bt;
            p[index].tat = p[index].et - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].rt = p[index].st - p[index].at;

            total_tat += p[index].tat;
            total_wt += p[index].wt;

            visited[index] = true;
            process_completed++;
            curr_time = p[index].et;
        }
        else
        {
            curr_time++;
        }
    }

    cout<<endl<<endl;

    cout<<"PID\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"ET\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].et<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }

    cout<<endl<<endl;

    cout<<"Average Turnaround Time is : "<<(float)total_tat/n<<endl;
    cout<<"Average Waiting Time is : "<<(float)total_wt/n<<endl;

return 0;
}

//5 0 3 3 1 4 2 2 6 4 3 4 6 5 2 10


6. Preemptive Priority Scheduling
#include<iostream>
using namespace std;

class process
{
    public:
    int at;
    int bt;
    int wt;
    int tat;
    int st;
    int et;
    int rt;
    int priority;
    int pid;
};

int main()
{
    cout<<"Enter the number of processes: "<<endl;
    int n;
    cin>>n;
    process p[n];
    bool visited[n];
    int curr_time=0;
    int remaining_bt[n];
    float avg_tat = 0;
    float avg_wt = 0; 
    int process_completed = 0;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter the arrival time for "<<i+1<<" process: "<<endl;
        cin>>p[i].at;
        cout<<"Enter the burst time for "<<i+1<<" process: "<<endl;
        cin>>p[i].bt;
        cout<<"Enter the priority of "<<i+1<<" process: "<<endl;
        cin>>p[i].priority;

        remaining_bt[i] = p[i].bt;
        p[i].pid = i+1;
    }

    while(process_completed != n)
    {
        int index = -1;
        int max_priority = -1;

        for(int i=0; i<n; i++)
        {
            if(p[i].at <= curr_time && !visited[i])
            {
                if(p[i].priority > max_priority)
                {
                    index = i;
                    max_priority = p[i].priority;
                }
                if(p[i].priority == max_priority)
                {
                    if(p[i].at < p[index].at)
                    {
                        index = i;
                        max_priority = p[i].priority;
                    }
                }
            }
        }

        if(index != -1)
        {
            if(remaining_bt[index] == p[index].bt )
            {
                p[index].st = curr_time;
            }

            remaining_bt[index] -= 1;
            curr_time++;

            if(remaining_bt[index] == 0)
            {
                p[index].et = curr_time;
                p[index].tat = p[index].et - p[index].at;
                p[index].wt = p[index].tat - p[index].bt;
                p[index].rt = p[index].st - p[index].at;

                process_completed++;
                visited[index] = 1;

                avg_tat += p[index].tat;
                avg_wt += p[index].wt;
            }
        }
        else
        {
            curr_time ++;
        }
    }

    cout<<endl<<endl;

    cout<<"PID\t"<<"AT\t"<<"BT\t"<<"P\t"<<"ST\t"<<"ET\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].priority<<"\t"<<p[i].st<<"\t"<<p[i].et<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }

    cout<<endl<<endl;

    cout<<"Average Turnaround Time is : "<<(float)avg_tat/n<<endl;
    cout<<"Average Waiting Time is : "<<(float)avg_wt/n<<endl;

return 0;
}


Banker’s Algorithm
#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the number of processes: "<<endl;
    int n;
    int m;
    cin>>n;
    cout<<"Enter the number of resources: "<<endl;
    cin>>m;

    int available[m];

    //Resource types
    for(int i=0; i<m; i++)
    {
        cout<<"Enter the available number of resources of resource type "<<i+1<<" : "<<endl;
        cin>>available[i];
    }

    int max[n][m];

    //defining max matrix: 
    for(int i=0; i<n; i++)
    {
        cout<<"For process "<<i+1<<" : "<<endl;
        for(int j=0; j<m; j++)
        {
            cout<<"Maximum need of resource type "<<j+1<<" : ";
            cin>>max[i][j];
        }
        cout<<endl;
    }


    int allocated[n][m];
    //defining allocation matrix: 
    for(int i=0; i<n; i++)
    {
        cout<<"For process "<<i+1<<" : "<<endl;
        for(int j=0; j<m; j++)
        {
            cout<<"Allocated resources of resource type "<<j+1<<" : ";
            cin>>allocated[i][j];
        }
        cout<<endl;
    }


    int need[n][m];
    //defining need matrix;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }


    //Safety algorithm

    //defining work vector
    int work[m];
    for(int i=0; i<m; i++)
    {
       work[i] = available[i];
    }
    //defining finish vector
    bool finish[n];
    for(int i=0; i<n; i++)
    {
        finish[i] = false;
    }
    bool flag;

    int ans[n];
    int z=0;
    for(int k=0; k<n; k++)
    {
        for(int i= 0; i<n; i++)
        {
            if(finish[i] == 0)
            {
                flag = 0;
                for(int j=0; j<m; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    ans[z++] = i+1;
                    for(int l=0; l<m; l++)
                    {
                        work[l] = work[l] + allocated[i][l];
                        finish[i] = true;
                    }
                }
            }
        }
    }

    bool res = true;
    for(int i=0; i<n; i++)
    {
        if(finish[i] == false)
        {
            res = false;
            cout<<"Deadlock"<<endl;
            break;
        }
    }

    if(res == true)
    {
        cout<<"Safe Condition"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<ans[i]<<" ";
        }
    }

return 0;
}


Memory Allocation Algorithm

1. First Fit Algorithm
#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the number of processes: "<<endl;
    int n=0;
    int m = 0;
    cin>>n;
    cout<<"Enter the number of blocks: "<<endl;
    cin>>m;

    int sizeofprocess[n];
    int sizeofblock[m];

    for(int i=0; i<n; i++)
    {
        sizeofprocess[i] = 0;
    }
    for(int i=0; i<m; i++)
    {
        sizeofblock[i] = 0;
    }

    //taking input of size of processes
    for(int i = 0; i<n; i++)
    {   
        cout<<"Enter the size of "<<i+1<<" processes: ";
        cin>>sizeofprocess[i];
    }

    //taking input of size of blocks
    for(int i = 0; i<m; i++)
    {
        cout<<"Enter the size of "<<i+1<<" block: ";
        cin>>sizeofblock[i];
    }

    int allocatedblock[n];
    for(int i=0; i<n; i++)
    {
        allocatedblock[i] = 0;
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(sizeofprocess[i] <= sizeofblock[j])
            {
                allocatedblock[i] = j +1 ;
                sizeofblock[j] -= sizeofprocess[i];
                break;
            }
        }
    }

    cout<<endl;

    //printing the table - 

    cout<<"Process No. \tProcess Size \tBlock No. \n";
    for(int i=0; i<n; i++)
    {
        cout<<" "<<i+1<<"\t\t"<<sizeofprocess[i]<<"\t\t";
        if(allocatedblock[i] != 0)
            cout<<allocatedblock[i];
        else
            cout<<"Not Allocated";
        cout<<endl;
    }

return 0;
}


2. Best Fit Algorithm
#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the number of processes: "<<endl;
    int n=0;
    int m = 0;
    cin>>n;
    cout<<"Enter the number of blocks: "<<endl;
    cin>>m;

    int sizeofprocess[n];
    int sizeofblock[m];

    for(int i=0; i<n; i++)
    {
        sizeofprocess[i] = 0;
    }
    for(int i=0; i<m; i++)
    {
        sizeofblock[i] = 0;
    }

    //taking input of size of processes
    for(int i = 0; i<n; i++)
    {   
        cout<<"Enter the size of "<<i+1<<" processes: ";
        cin>>sizeofprocess[i];
    }

    //taking input of size of blocks
    for(int i = 0; i<m; i++)
    {
        cout<<"Enter the size of "<<i+1<<" block: ";
        cin>>sizeofblock[i];
    }

    int allocatedblock[n];
    for(int i=0; i<n; i++)
    {
        allocatedblock[i] = 0;
    }

    for(int i = 0; i<n; i++)
    {
        int min_index = -1;
        for(int j = 0; j<m; j++)
        {
            if(sizeofblock[j] >= sizeofprocess[i])
            {
                if(min_index == -1)
                {
                    min_index = j;
                }
                else if(sizeofblock[min_index] > sizeofblock[j])
                {
                    min_index = j;
                }
            }
        }

        if(min_index == -1)
        {
            allocatedblock[i] = -1;
        }
        else
        {
            allocatedblock[i] = min_index + 1;
            sizeofblock[min_index] -= sizeofprocess[i];
        }
    }

    cout<<endl;

    //printing the table - 

    cout<<"Process No. \tProcess Size \tBlock No. \n";
    for(int i=0; i<n; i++)
    {
        cout<<" "<<i+1<<"\t\t"<<sizeofprocess[i]<<"\t\t";
        if(allocatedblock[i] != -1)
            cout<<allocatedblock[i];
        else
            cout<<"Not Allocated";
        cout<<endl;
    }

return 0;
}
// 4 5 212 417 112 426 100 500 200 300 600


3. Worst Fit Algorithm
#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the number of processes: "<<endl;
    int n=0;
    int m = 0;
    cin>>n;
    cout<<"Enter the number of blocks: "<<endl;
    cin>>m;

    int sizeofprocess[n];
    int sizeofblock[m]; 
    

    for(int i=0; i<n; i++)
    {
        sizeofprocess[i] = 0;
    }
    for(int i=0; i<m; i++)
    {
        sizeofblock[i] = 0;
    }

    //taking input of size of processes
    for(int i = 0; i<n; i++)
    {   
        cout<<"Enter the size of "<<i+1<<" processes: ";
        cin>>sizeofprocess[i];
    }

    //taking input of size of blocks
    for(int i = 0; i<m; i++)
    {
        cout<<"Enter the size of "<<i+1<<" block: ";
        cin>>sizeofblock[i];
    }

    int allocatedblock[n];
    for(int i=0; i<n; i++)
    {
        allocatedblock[i] = 0;
    }

    for(int i = 0; i<n; i++)
    {
        int max_index = -1;
        for(int j = 0; j<m; j++)
        {
            if(sizeofblock[j] >= sizeofprocess[i])
            {
                if(max_index == -1)
                {
                    max_index = j;
                }
                else if(sizeofblock[max_index] < sizeofblock[j])
                {
                    max_index = j;
                }
            }
        }

        if(max_index == -1)
        {
            allocatedblock[i] = -1;
        }
        else
        {
            allocatedblock[i] = max_index + 1;
            sizeofblock[max_index] -= sizeofprocess[i];
        }
    }

    cout<<endl;

    //printing the table - 

    cout<<"Process No. \tProcess Size \tBlock No. \n";
    for(int i=0; i<n; i++)
    {
        cout<<" "<<i+1<<"\t\t"<<sizeofprocess[i]<<"\t\t";
        if(allocatedblock[i] != -1)
            cout<<allocatedblock[i];
        else
            cout<<"Not Allocated";
        cout<<endl;
    }

return 0;
}
// 4 5 212 417 112 426 100 500 200 300 600 

Disk Scheduling Algorithms


1. FCFS Algorithm
#include<iostream>
using namespace std;
int main()
{
    int total_head_movement = 0;
    int n;
    int head;

    //request sequence
    cout<<"Enter the size of queue: "<<endl;
    cin>>n;
    
    int queue[n]; 

    cout<<"Enter the position where head starts: "<<endl;
    cin>>head;

    cout<<"Enter the request queue: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>queue[i];
    }

    for(int i=0;i<n;i++)
    {
        total_head_movement += abs(head - queue[i]);
        head = queue[i];
    }    

    cout<<endl<<"The total head movement is: "<<total_head_movement<<endl;
    cout<<"Seek Sequence is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<queue[i]<<" ";
    }
    cout<<endl;
return 0;
}

2. SSTF Algorithm
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of queue: "<<endl;
    cin>>n;
    int queue[n];
    int seek_sequence[n];

    int head = 0;

    cout<<"Enter the position where head starts: "<<endl;
    cin>>head;

    cout<<"Enter the request queue: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>queue[i];
    }

    bool visited[n];
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }

    int total_head_movement = 0;
    int i=0;
    int completed = 0;

    while(completed != n)
    {
        int min = INT_MAX;
        int index = -1;
        for(int i=0; i<n; i++)
        {
            if(visited[i] == false && abs(head - queue[i]) < min)
            {
                min = abs(head - queue[i]);
                index = i;
            }
        }

        total_head_movement += min;
        head = queue[index];
        seek_sequence[i++] = queue[index];
        visited[index] = true;
        completed++;
    }

    cout<<endl<<"The total head movement is: "<<total_head_movement<<endl;
    cout<<"Seek Sequence is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<seek_sequence[i]<<" ";
    }
    cout<<endl;
   
    //8 53 98 183 37 122 14 124 65 67

return 0;
}

3. Scan Algorithm
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of queue: "<<endl;
    cin>>n;
    vector<int> queue(n);
    vector<int> seek_sequence;

    int head = 0;

    cout<<"Enter the position where head starts: "<<endl;
    cin>>head;

    int last_track;
    cout<<"Enter the last track: "<<endl;
    cin>>last_track;

    cout<<"Enter the request queue: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>queue[i];
    }

    int direction;
    cout<<"For direction: Enter 0 if moving towards higher track else 1: "<<endl;
    cin>>direction;

    int total_head_movement = 0;

    vector<int> left;
    vector<int> right;

    if(direction == 0)
    {
        if(head > *min_element(queue.begin(), queue.end()))
            right.push_back(last_track);
        right.push_back(head);
    }
    else
    {
        if(head < *max_element(queue.begin(), queue.end()))
            left.push_back(0);
        left.push_back(head);
    }

    for(int i=0; i<n; i++)
    {
        if(queue[i] > head)
        {
            int z = queue[i];
            right.push_back(z);
        }
        else
        {
            left.push_back(queue[i]);
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int completed = 2;
    while (completed--)
    {
        if (direction == 0) 
        {
            for (int i = 0; i < right.size(); i++) 
            {
                total_head_movement += abs(head - right[i]);    
                head = right[i];
                seek_sequence.push_back(right[i]); 
            }
            direction = 1;
        }
        else if (direction == 1)
        {
            for (int i = left.size() - 1; i >= 0; i--) 
            {
                total_head_movement +=  abs(head - left[i]);    
                head = left[i];
                seek_sequence.push_back(left[i]); 
            }
            direction = 0;
        }
    } 

    cout<<endl<<"The total head movement is: "<<total_head_movement<<endl;
    cout<<"Seek Sequence is: "<<endl;
    for(int i=0; i<seek_sequence.size(); i++)
    {
        cout<<seek_sequence[i]<<" ";
    }
    cout<<endl;

    //8 53 199 98 183 37 122 14 124 65 67 1

return 0;
}


4.C-Scan Algorithm
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int total_head_movement=0;
    int n;

    cout<<"Enter the size of queue: "<<endl;
    cin>>n;
    
    vector<int> queue(n);
    vector<int> seek_sequence;

    int head = 0;

    cout<<"Enter the position where head starts: "<<endl;
    cin>>head;

    int last_track;
    cout<<"Enter the last track: "<<endl;
    cin>>last_track;

    cout<<"Enter the request queue: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>queue[i];
    }

    int direction;
    cout<<"For direction: Enter 0 if moving towards higher track else 1: "<<endl;
    cin>>direction;

    vector<int> left;
    vector<int> right;

    if(direction == 0)
        right.push_back(head);
    else if(direction == 1)
        left.push_back(head);    

    for (int i = 0; i<n; i++) 
    {
        if (queue[i] < head)
            left.push_back(queue[i]);
        if (queue[i] > head)
            right.push_back(queue[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    if(direction == 0 )
    {
        for (int i = 0; i < right.size(); i++) 
        {
            total_head_movement += abs(head - right[i]);    
            head = right[i];
            seek_sequence.push_back(right[i]); 
        }
        for (int i = 0; i < left.size(); i++) 
        {
            total_head_movement += abs(head - left[i]); 
            head = left[i];
            seek_sequence.push_back(left[i]); 
        }
    }
    else if(direction == 1)
    {
        int total_head_movement=0; 
        for (int i = left.size() - 1; i >=0; i--) 
        {
            total_head_movement += abs(head - left[i]); 
            head = left[i];
            seek_sequence.push_back(left[i]); 
        }
        
        for (int i = right.size() -1; i >=0; i--)
        {
            total_head_movement += abs(head - right[i]);    
            head = right[i];
            seek_sequence.push_back(right[i]); 
        }
    }

    cout<<endl<<"The total head movement is: "<<total_head_movement<<endl;
    cout<<"Seek Sequence is: "<<endl;
    for(int i=0; i<seek_sequence.size(); i++)
    {
        cout<<seek_sequence[i]<<" ";
    }
    cout<<endl;

    //8 53 199 98 183 37 122 14 124 65 67 0

    return 0;
}


5.C-Look Algorithm
#include<iostream>

#include<vector>
using namespace std;

int main()
{
    int total_head_movement=0;
    int n;

    cout<<"Enter the size of queue: "<<endl;
    cin>>n;                                
    
    vector<int> queue(n);
    vector<int> seek_sequence;

    int head = 0;

    cout<<"Enter the position where head starts: "<<endl;
    cin>>head;

    int last_track;
    cout<<"Enter the last track: "<<endl;
    cin>>last_track;

    cout<<"Enter the request queue: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>queue[i];
    }

    int direction;
    cout<<"For direction: Enter 0 if moving towards higher track else 1: "<<endl;
    cin>>direction;

    vector<int> left;
    vector<int> right;

    if(direction == 0)
        right.push_back(head);
    else if(direction == 1)
        left.push_back(head);    

    for (int i = 0; i<n; i++) 
    {
        if (queue[i] < head)
            left.push_back(queue[i]);
        if (queue[i] > head)
            right.push_back(queue[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    if(direction == 0 )
    {
        for (int i = 0; i < right.size(); i++) 
        {
            total_head_movement += abs(head - right[i]);    
            head = right[i];
            seek_sequence.push_back(right[i]); 
        }
        for (int i = 0; i < left.size(); i++) 
        {
            total_head_movement += abs(head - left[i]); 
            head = left[i];
            seek_sequence.push_back(left[i]); 
        }
    }
    else if(direction == 1)
    {
        int total_head_movement=0; 
        for (int i = left.size() - 1; i >=0; i--) 
        {
            total_head_movement += abs(head - left[i]); 
            head = left[i];
            seek_sequence.push_back(left[i]); 
        }
        
        for (int i = right.size() -1; i >=0; i--)
        {
            total_head_movement += abs(head - right[i]);    
            head = right[i];
            seek_sequence.push_back(right[i]); 
        }
    }

    cout<<endl<<"The total head movement is: "<<total_head_movement<<endl;
    cout<<"Seek Sequence is: "<<endl;
    for(int i=0; i<seek_sequence.size(); i++)
    {
        cout<<seek_sequence[i]<<" ";
    }
    cout<<endl;

    //8 53 199 98 183 37 122 14 124 65 67 0

    return 0;

}

