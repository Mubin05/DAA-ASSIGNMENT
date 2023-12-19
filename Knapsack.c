#include <stdio.h>
#include <stdlib.h>
void knapsack(float w[], float p[], int n, int m);
int main() {
    int m, n, i;
    printf("enter max wt of knapsack: ");
    scanf("%d", &m);
    printf("\nenter no. of objects: ");
    scanf("%d", &n);
    float w[n], p[n];
    printf("enter weights\n");
    for (i = 0; i < n; i++) {
        printf("w[%d]= ", i);
        scanf("%f", &w[i]);
    }
    printf("\nenter profits\n");
    for (i = 0; i < n; i++) {
        printf("p[%d]= ", i);
        scanf("%f", &p[i]);
    }
    knapsack(w, p, n, m);
    return 0;
}
void knapsack(float w[], float p[], int n, int m) {
    int i, j;
    float cal[n], x[n], prof = 0;
    int wt = 0, k = 0;
    for (i = 0; i < n; i++) {
        x[i] = 0;
    }
    for (i = 0; i < n; i++) {
        cal[i] = p[i] / w[i];
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (cal[i] < cal[j]) {
                float t1 = cal[i], t2 = w[i], t3 = p[i];
                cal[i] = cal[j];
                w[i] = w[j];
                p[i] = p[j];
                cal[j] = t1;
                w[j] = t2;
                p[j] = t3;
            }
        }
    }
    printf("\n\n p[i]\t\t w[i]\t\t cal[i]\n");
    for (i = 0; i < n; i++) {
        printf("%f\t %f\t %f\t\n", p[i], w[i], cal[i]);
    }
    for (i = 0; i < n; i++) {
        if ((wt + w[i]) <= m) {
            k++;
            x[i] = 1;
            wt += w[i];
            prof += (x[i] * p[i]);
            p[i] = (x[i] * p[i]);
        } else {
            break;
        }
    }
    printf("\nthe selected wts are: \n");
    for (i = 0; i < k; i++) {
        printf("%d\t%f\t%f\n", i + 1, w[i], p[i]);
    }
    printf("\n the total profit is %f\n",prof);
}
