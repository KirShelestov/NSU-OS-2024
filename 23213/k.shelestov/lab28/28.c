#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <libgen.h>

#define NUM_COUNT 100

extern int p2open(const char *, FILE *[2]); 
extern int p2close(FILE *[2]);              

int main() {
    FILE *sort_fp[2]; 
    FILE *fp[2];     
    int i;

    srand(time(NULL));

    // Открываем процесс сортировки для записи
    if (p2open("/usr/bin/sort -n", sort_fp) == -1) {
        perror("Error opening sort for writing");
        return 1;
    }

    // Генерируем случайные числа и записываем их в сортируемый процесс
    for (i = 0; i < NUM_COUNT; i++) {
        fprintf(sort_fp[1], "%d\n", rand() % 100); 
    }

    // Закрываем поток записи
    if (p2close(sort_fp) == -1) {
        perror("Error closing sort after writing");
        return 1;
    }

    // Открываем процесс сортировки для чтения
    if (p2open("/usr/bin/sort -n", fp) == -1) { 
        perror("Error opening sort for reading");
        return 1; 
    }

    char line[10];
    i = 0;

    // Читаем отсортированные числа и выводим их на экран
    while (fgets(line, sizeof(line), fp[0]) != NULL) { 
        printf("%s", line);
        fflush(stdout);
        if (++i % 10 == 0) {
            printf("\n"); 
        }
    } 


    if (p2close(fp) == -1) {
        perror("Error closing sort after reading");
        return 1;
    }

    return 0;
}

