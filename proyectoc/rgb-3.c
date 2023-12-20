#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo %s\n", argv[1]);
        return 1;
    }

    int r, g, b;
    while (fscanf(file, "%d %d %d", &r, &g, &b) == 3)
    {
        printf("RGB: (%d, %d, %d)\n", 255 - r, 255 - g, 255 - b);
        printf("HEX: 0x%02x%02x%02x\n", 255 - r, 255 - g, 255 - b);
    }

    fclose(file);
    return 0;
}