#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int array[10],n;
void descending();

int main(void)
{
    int i,j;
    printf("\nEnter the no of array:");
    scanf("%d",&n);
    printf("\nEnter the array:");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    int pid = fork();
    if(pid==0)
    {
        printf("\nChild Process is Executing");
        descending();
    }
    else
    {
        printf("\nParent Process is Executing");
        descending();
    }
    
    return 0;
}


void descending()
{
    int i,j,k,temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(array[i]<array[j])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    
    printf("\n\nThe no in Descending order are:\n");
    for(i=0;i<n;i++)
        printf("%d\t",array[i]);
}
