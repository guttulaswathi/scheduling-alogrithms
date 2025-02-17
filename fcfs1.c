#include <stdio.h>
void findWaitingTime(int processes[], int n,  
                          int bt[], int wt[]) 
{ 
    wt[0] = 0; 
    for (int  i = 1; i < n ; i++ ) 
        wt[i] =  bt[i-1] + wt[i-1] ; 
} 
  

void findavgTime( int processes[], int n, int bt[]) 
{ 
    int wt[n], total_wt = 0;
  
    findWaitingTime(processes, n, bt, wt); 
    printf("processes brusttime waitingtime \n");
    for (int  i=0; i<n; i++) 
    { 
        printf("%d ",(i+1));
        printf("        %d ", bt[i] );
        printf("        %d\n",wt[i] );
        total_wt = total_wt + wt[i]; 
    } 
    float s=(float)total_wt / (float)n;
    printf("\n");
    printf("Average waiting time = %f",s);
} 

int main() {
   int processes[] = { 1, 2, 3}; 
    int n = sizeof processes / sizeof processes[0]; 
    int  burst_time[] = {10, 5, 8}; 
    findavgTime(processes, n,  burst_time); 
    return 0;
}
