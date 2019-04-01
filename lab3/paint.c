#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct point {
    int x, y;
} point;

typedef struct queue {
    int start, ending, size;
    point **elements;
} queue;


queue *new_queue(int size) {
    queue *q = malloc(sizeof(queue));
    q->size = size;
    q->start = 0;
    q -> ending = 0;
    q->elements = malloc(size*sizeof(point*));
    for(int i=0; i<size; i++) q->elements[i]=NULL;
    return q;
}

void delete_queue(queue *q) {
    free(q->elements);
    free(q);
}

void put(queue *q, point *value) {
    q->elements[q->ending] = value;
    q->ending++;
    if(q->ending>=q->size) q->ending=0;
}

bool is_empty(queue *q) {
    if(q->start == q->ending) return true;
    return false;
}

point *get(queue *q) {
    if(is_empty(q)) return 0;
    point* value = q->elements[q->start];
    q->start++;
    if(q->start>=q->size) q->start=0;
    return value;
}


bool is_white(int **image, int x, int y){
    if(image[x][y]==0) return true;
    return false;
}

void fill(int **image, int n, int x, int y, int color) {
    queue *points = new_queue(n * n);
    point * p = malloc(sizeof(point));
    point *tmp;
    p->x=x; p->y=y;
    put(points, p);
    while (!is_empty(points)) {

        p = get(points);
        image[p->x][p->y] = color;
        if(p->x + 1 < n && is_white(image, p->x +1, p->y)){
            tmp=malloc(sizeof(point));
            tmp->x=p->x+1; tmp->y=p->y;
            put(points, tmp);
        }
        if(p->x - 1 >= 0 && is_white(image, p->x -1, p->y)){
            tmp=malloc(sizeof(point));
            tmp->x=p->x-1; tmp->y=p->y;
            put(points, tmp);
        }
        if(p->y + 1< n && is_white(image, p->x, p->y + 1)){
            tmp=malloc(sizeof(point));
            tmp->x=p->x; tmp->y=p->y+1;
            put(points, tmp);
        }
        if(p->y-1>=0 && is_white(image, p->x, p->y - 1)){
            tmp=malloc(sizeof(point));
            tmp->x=p->x; tmp->y=p->y-1;
            put(points, tmp);
        }
    }
    delete_queue(points);
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int **image = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        image[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int x, y, color;
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%d", &color);
        fill(image, n, x, y, color);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
        free(image[i]);
    }
    free(image);
}