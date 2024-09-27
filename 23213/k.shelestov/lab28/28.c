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


    if (p2open("sort", sort_fp) == -1) {
        perror("Error with open sort");
        return 1;
    }


    for (i = 0; i < NUM_COUNT; i++) {
        fprintf(sort_fp[1], "%d\n", rand() % 100); 
    }
    p2close(sort_fp); 


    if (p2open("sort", fp) == -1) { 
        perror("Error with open sort for reading");
        return 1; 
    }

    char line[10];
    i = 0;

    while (fgets(line, sizeof(line), fp[0]) != NULL) { 
        printf("%s", line);
        if (++i % 10 == 0) {
            printf("\n"); 
        }
    } 


    p2close(fp); 
    return 0;
}

