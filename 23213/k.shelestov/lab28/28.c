#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <libgen.h>
#define NUM_COUNT 100
int main() {
    FILE *fp;
    int i;
    srand(time(NULL));
    FILE *sort_fp;
    if ((sort_fp = p2open("sort", "w")) == NULL) {
        perror("Error with open sort");
        return 1;
    }
    for (i = 0; i < NUM_COUNT; i++) {
        fprintf(sort_fp, "%d\n", rand() % 100); 
    }
    p2close(sort_fp);
    if ((fp = p2open("sort -n", "r")) == NULL) { 
        perror("Error with open sort for reading");
        return 1; 
    }
    char line[10];
    i = 0;
    while (fgets(line, sizeof(line), fp) != NULL) { 
        printf("%s", line);
        if (++i % 10 == 0) {
            printf("\n"); 
        }
    } 
    p2close(fp);
    return 0;
} 
