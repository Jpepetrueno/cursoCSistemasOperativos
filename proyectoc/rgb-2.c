#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int r;
    int g;
    int b;
} RGB;

void set(RGB *color, int r, int g, int b)
{
    if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255))
    {
        color->r = r;
        color->g = g;
        color->b = b;
    }
}

void invert(RGB *color)
{
    set(color, 255 - color->r, 255 - color->g, 255 - color->b);
}

void print_color(RGB *color)
{
    printf("RGB: (%d, %d, %d)\n", color->r, color->g, color->b);
    printf("HEX: 0x%02x%02x%02x\n", color->r, color->g, color->b);
}

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo %s\n", argv[1]);
        return 1;
    }

    RGB color;
    while (fscanf(file, "%d %d %d", &color.r, &color.g, &color.b) == 3)
    {
        invert(&color);
        print_color(&color);
    }

    fclose(file);
    return 0;
}