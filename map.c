#include "map.h"

int main(int argc, char **argv) {
    if (argc < 7 || argc > 7) {
        printf("Not enough arguments !\n");
        return 1;
    }
    if (!isdigit(*argv[1]) || !isdigit(*argv[2]) || !isdigit(*argv[5])) {
        printf("Invalid arguments !\n");
        return 1;
    }
    int l = atoi(argv[1]), c = atoi(argv[2]), op = atoi(argv[5]);
    char e = *argv[3], o = *argv[4], f = *argv[6];

    char **tab;
    if (!(tab = calloc(l, sizeof(char*)))) {
        printf("Allocation fail !\n");
        return 1;
    }
    for (unsigned int i=0; i<l; i++) {
        if (!(tab[i] = calloc(c, sizeof(char)))) {
            printf("Allocation fail !\n");
            return 1;
        }
    }

    srand(time(NULL));
    for (unsigned int i=0; i<l; i++) {
        for (unsigned int j=0; j<c; j++) {
            if (rand()%100 > op) {
                tab[i][j] = e;
            } else {
                tab[i][j] = o;
            }
        }
    }
    printf("%d %c %c %c\n", l, e, o, f);
    printf("%d %d\n", c, op);
    for (unsigned int i=0; i<l; i++) {
        for (unsigned int j=0; j<c; j++) {
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }

    return 0;
}