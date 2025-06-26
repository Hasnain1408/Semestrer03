#include <stdio.h>

int main()
{
    FILE *file;
    char currentChar, nextChar;
    int line=1;

    file = fopen("Untitled2.c", "r");

    if (file == NULL) {
        printf("File not found.\n");
        return 0;
    }


    while ((currentChar = fgetc(file)) != EOF) {
        if(currentChar == '\n') line++;
        if (currentChar == '/') {
            nextChar = fgetc(file);

            if (nextChar == '/') {
                printf("line:%d -> ",line);
                while ((currentChar = fgetc(file)) != EOF && currentChar != '\n') {
                    putchar(currentChar);
                }
                line++;
                putchar('\n');
            } else if (nextChar == '*') {
                printf("line:%d -> ",line);
                while ((currentChar = fgetc(file)) != EOF) {
                     if(currentChar == '\n') line++;
                    if (currentChar == '*' && (nextChar = fgetc(file)) == '/') break;
                     putchar(currentChar);
                }
               putchar('\n');
            }
        }
    }

    fclose(file);

    return 0;
}
