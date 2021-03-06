#include "StatusTree.h"

int main(int argc, char **argv) {
    size_t bufferSize = BUFFER_SIZE;
    if(argc != 3) {
        puts("Expected 2 strings");
        exit(-1);
    }
    freopen(argv[1], "r", stdin);
    NODE *root= NULL;

    char *line = malloc(BUFFER_SIZE);
    scanf("%[^\r\n]", line);
    scanf("%*c");
    scanf("%*c");

    int numLines;
    sscanf(line, "%d", &numLines);

    for (int i = 0; i < numLines; i++) {
        getline(&line, &bufferSize, stdin);
        STATUS *data = malloc(sizeof(STATUS));
        sscanf(line, "%d%[^\r\n]", &data->laptopNum, data->status);
        if(!add(&root, data)) {
            printf("Data not added because laptop with number %d already exists", data->laptopNum);
            free(data);
        }
    }

    FILE *file = fopen(argv[2], "w+");

    printTable(file, &root);

    fclose(file);

    freeNode(&root);
    free(line);
    return 1;
}
