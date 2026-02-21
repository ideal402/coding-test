#include <stdio.h>

#define MAX_N 80000

int main(){
    int n;
    int stack[MAX_N];

    int top = 0;

    long long ans = 0;

    if(scanf("%d", &n) != 1) return 0;

    for(int i = 0; i<n; i++){
        int height;
        scanf("%d", &height);

        while (top > 0 && stack[top - 1] <= height)
        {
            top--;
        }

        ans += top;

        stack[top++] = height;
    }

    printf("%lld\n", ans);
}