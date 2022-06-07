#include <stdio.h>
int main()
{
    int n, m, i, j, k;
    n = 6;
    m = 4;
    int alloc[6][4] = { { 0, 1, 0, 3 },
        { 2, 0, 0, 3 },
        { 3, 0, 2, 0 },
        { 2, 1, 1, 5 },
        { 0, 0, 2, 2 },
        {1, 2 , 3, 1 } };
    int max[6][4] = { { 6, 4, 3, 4 },
        { 3, 2, 2, 4 },
        { 9, 1, 2, 6 },
        { 2, 2, 2, 8 },
        { 4, 3, 3, 7 },
        { 6, 2 , 6, 5 } };
    
    int avail[4] = { 2, 2, 2, 1 };
    
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                        break;
                    }
                }
                
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    
    int flag = 1;
    
    for(int i=0;i<n;i++)
    {
        if(f[i]==0)
        {
            flag=0;
            printf("Deadlock Ahead");
            break;
        }
    }
    
    if(flag==1)
    {
        printf("Safe Sequence is: ");
        for (i = 0; i < n - 1; i++)
        {
            printf(" P%d ->", ans[i]);
        }
        
        printf(" P%d", ans[n - 1]);
        
    }
    
    return (0);
}


