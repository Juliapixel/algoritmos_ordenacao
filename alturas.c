#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int trocas;
    int comparacoes;
} Metricas;

void bubble_asc(float *buf, size_t n, Metricas *m) {
    int trocou;
    do {
        trocou = 0;
        for (size_t i = 0; i < n - 1; i++)
        {
            m->comparacoes += 1;
            if (buf[i] > buf[i+1]) {
                float tmp = buf[i];
                buf[i] = buf[i+1];
                buf[i+1] = tmp;
                m->trocas += 1;
                trocou = 1;
            }
        }
    } while (trocou);
}

void insertion_asc(float *buf, size_t n, Metricas *m) {
    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = i; j >= 1; j--)
        {
            m->comparacoes += 1;
            if (buf[j] < buf[j-1]) {
                float tmp = buf[j];
                buf[j] = buf[j-1];
                buf[j-1] = tmp;
                m->trocas += 1;
            } else {
                break;
            }
        }
    }
}

void selection_asc(float *buf, size_t n, Metricas *m) {
    for (size_t i = 0; i < n; i++)
    {
        size_t idx_min = i;
        for (size_t j = i; j < n; j++)
        {
            if (buf[j] < buf[idx_min]) idx_min = j;
            m->comparacoes += 1;
        }
        float tmp = buf[i];
        buf[i] = buf[idx_min];
        buf[idx_min] = tmp;
        m->trocas += 1;
    }

}

void print_metricas(Metricas *m) {
    printf("Trocas: %d\nComparações: %d\n", m->trocas, m->comparacoes);
}

void print_buf(float *buf, size_t n) {
    printf("[\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("\t%f,\n", buf[i]);
    }
    printf("]\n");
}

void reset_metricas(Metricas *m) {
    m->comparacoes = 0;
    m->trocas = 0;
}

#define BUF_LEN 10

int main(int argc, char const *argv[])
{
    float *buf = malloc(sizeof(float) * BUF_LEN);

    printf("Digite as 10 alturas (em cm):\n");
    for (size_t i = 0; i < BUF_LEN; i++)
    {
        printf("Altura %lld: ", i+1);
        scanf("%f", &buf[i]);
    }

    printf("=========VETOR DESORDENADO==========\n");
    print_buf(buf, BUF_LEN);

    float *buf2 = malloc(sizeof(float) * BUF_LEN);
    memcpy(buf2, buf, sizeof(float) * BUF_LEN);
    float *buf3 = malloc(sizeof(float) * BUF_LEN);
    memcpy(buf3, buf, sizeof(float) * BUF_LEN);

    Metricas m;
    reset_metricas(&m);

    printf("========BUBBLE SORT=========\n");
    bubble_asc(buf, BUF_LEN, &m);
    print_buf(buf, BUF_LEN);
    print_metricas(&m);
    reset_metricas(&m);

    printf("========INSERTION SORT=========\n");
    insertion_asc(buf2, BUF_LEN, &m);
    print_buf(buf2, BUF_LEN);
    print_metricas(&m);
    reset_metricas(&m);

    printf("========SELECTION SORT==========\n");
    selection_asc(buf3, BUF_LEN, &m);
    print_buf(buf3, BUF_LEN);
    print_metricas(&m);
    reset_metricas(&m);

    free(buf);
    free(buf2);
    free(buf3);

    return 0;
}
