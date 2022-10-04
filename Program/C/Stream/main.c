#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *filename = "/home/nguyen/Embedded/Program/C/Stream/data.txt";

const char *data_input = "Hello World!";

char buffer[12];

int main(int agrv, const char *argc[])
{
    FILE *stream;
    stream = fopen(filename, "r+");
    if (stream == NULL)
    {
        printf("Cannot open file ! \n");
    }
    size_t fw = fwrite(data_input, sizeof(char), strlen(data_input), stream);
    if (fw < strlen(data_input))
    {
        printf("Cannot write to file");
    }
    fseek(stream, 0, SEEK_SET);

    fread(&buffer, sizeof(char), 12, stream);

    int value_close = fclose(stream);
    if (value_close != 0)
    {
        printf("Cannot close file ! \n");
    }

    printf("%s \n", buffer);
    return 0;
}
