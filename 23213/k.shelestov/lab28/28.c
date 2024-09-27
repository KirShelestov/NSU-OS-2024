#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 100
           
int main() {
    FILE *sort_fp[2]; 
    FILE *fp[2];     
    int i;

    srand(time(NULL));


    if (p2open("/usr/bin/sort -n", sort_fp) == -1) {
        perror("Error opening sort for writing");
        return 1;
    }


    for (i = 0; i < NUM_COUNT; i++) {
        fprintf(sort_fp[1], "%d\n", rand() % 100); 
    }
    

    if (p2close(sort_fp) == -1) {
        perror("Error closing sort after writing");
        return 1;
    }


    if (p2open("/usr/bin/sort -n", fp) == -1) { 
        perror("Error opening sort for reading");
        return 1; 
    }

    char line[10];
    i = 0;


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

