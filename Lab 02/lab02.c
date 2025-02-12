#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
typedef struct {
    double x, y;
} Entity;
 
// Função para comparar por coordenada X
int compareX(const void *a, const void *b) {
    Entity *e1 = (Entity *)a;
    Entity *e2 = (Entity *)b;
    return (e1->x < e2->x) ? -1 : (e1->x > e2->x);
}
 
// Função para comparar por coordenada Y
int compareY(const void *a, const void *b) {
    Entity *e1 = (Entity *)a;
    Entity *e2 = (Entity *)b;
    return (e1->y < e2->y) ? -1 : (e1->y > e2->y);
}
 
// Função para calcular a distância entre dois pontos
double calculate_distance(Entity e1, Entity e2) {
    return sqrt(pow(e1.x - e2.x, 2) + pow(e1.y - e2.y, 2));
}
 
// Função que encontra a menor distância em uma faixa de pontos
double strip_closest(Entity strip[], int size, double d) {
    double min = d;
    qsort(strip, size, sizeof(Entity), compareY);
 
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j) {
            double dist = calculate_distance(strip[i], strip[j]);
            if (dist < min) {
                min = dist;
            }
        }
    }
    return min;
}
 
// Função principal usando divisão e conquista
double closest_recursive(Entity entities[], int left, int right) {
    if (right - left <= 3) {
        double min_dist = 1e9;
        for (int i = left; i < right; ++i) {
            for (int j = i + 1; j < right; ++j) {
                double dist = calculate_distance(entities[i], entities[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                }
            }
        }
        return min_dist;
    }
 
    int mid = (left + right) / 2;
    double dl = closest_recursive(entities, left, mid);
    double dr = closest_recursive(entities, mid, right);
 
    double d = fmin(dl, dr);
 
    Entity strip[right - left];
    int strip_size = 0;
    for (int i = left; i < right; i++) {
        if (fabs(entities[i].x - entities[mid].x) < d) {
            strip[strip_size++] = entities[i];
        }
    }
 
    return fmin(d, strip_closest(strip, strip_size, d));
}
 
int main() {
    int N;
    scanf("%d", &N);
 
    Entity entities[N];
    for (int i = 0; i < N; i++) {
        scanf("%lf %lf", &entities[i].x, &entities[i].y);
    }
 
    qsort(entities, N, sizeof(Entity), compareX);
 
    double min_distance = closest_recursive(entities, 0, N);
    printf("%.10f\n", min_distance);
 
    return 0;
}