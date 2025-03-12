#include <stdio.h>

struct Ex {
    int x;
    int y;
};

int main(){
    struct Ex e = {.y =15, .x=5};
    printf("%d", e.y);

    return 0;
}