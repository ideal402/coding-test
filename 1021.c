#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int q[10000];
int head = 0;
int tail = 0;

int main(){

    int n, m, temp;

    scanf("%d %d", &n, &m);

    for (int i = 1; i<=n; i++){
        q[tail++] = i;
    }

    int ans = 0;

    for(int i=0; i<m; i++){
        scanf("%d", &temp);
        int cnt = 0;

        while(q[head] != temp){
            q[tail++] = q[head++];
            cnt++;
        }

        ans += MIN(cnt, (tail-head)-cnt);

        head++;

    }


    printf("%d", ans);

    return 0;
}