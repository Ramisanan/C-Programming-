#include <stdio.h>
#include <string.h>
#define N 30

int main(void)
{
    int arr1[100];
    int q;
    int n = 11;
    int i, j, tmp;
    char s[N];
    
    int k = 3;
    for(i=0;i<k;i++){
        printf("Name of the team: ");
        scanf("%s",s);
        printf("Id of the team: ");
        scanf("%d",&q);
        printf("Input all %d players scores in an array:\n",n);
        for(i=1;i<=n;i++)
        {
            printf("Goals of players %d : ",i);
            scanf("%d",&arr1[i]);
        }
    }
    
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr1[i] < arr1[j])
            {
                tmp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = tmp;
            }
        }
    }
   
    printf("\n\n");
}


