#include <stdio.h>

#define MX 1000005

int q[MX];
int head = 0;
int tail = 0;

void push(int x) {
    q[tail++] = x;
}

void pop() {
    head++;
}

int front(){
    return q[head];
}
int size(){
    return tail - head;
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        push(i);
    }

    while(size() != 1){
        pop();
        int x = front();
        push(x);
        pop();
    }

    printf("%d", front());

    return 0;
}