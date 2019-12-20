#include "map.h"

int main(int argc, char **argv) {
    if (argc != 7) {
        printf("Not enough arguments !\n");
        return 1;
    }

    char *endPtr[3];
    long l = strtol(argv[1], &endPtr[0], 10);
    long c = strtol(argv[2], &endPtr[1], 10);
    long op = strtol(argv[5], &endPtr[2], 10);
    for (unsigned int i=0; i<3; i++) {
        if (*endPtr[i] != '\0') {
            printf("Invalid arguments !\n");
            return 1;
        }
    }

    char e = *argv[3], o = *argv[4], f = *argv[6];

    char *line;
    if (!(line = malloc((c+1)*sizeof(char)))) {
        printf("Allocation fail !\n");
        return 1;
    }
    line[c] = '\n';

    FILE *ftpr;
    ftpr = fopen("map.res", "w");
    if (ftpr == NULL) {
        printf("Can't open file !\n");
        return 1;
    }
    fprintf(ftpr, "%ld%c%c%c\n", l, e, o, f);

    srand(time(NULL));
    for (unsigned long i=0; i<l; i++) {
        for (unsigned long j=0; j<c; j++) {
            if (rand()%100 > op) {
                line[j] = e;
            } else {
                line[j] = o;
            }
        }
        fwrite(line, sizeof(char), c+1, ftpr);
        fflush(stdout);
        printf("\r%.0f%%", ((float)i/(float)l)*100);
    }
    printf("\n");

    fclose(ftpr);
    free(line);
    return 0;
}
