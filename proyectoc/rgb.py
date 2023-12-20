#!/bin/python
from sys import argv

class RGB:
    """
    Clase para representar un color en formato RGB.
    """
    def __init__(self):
        """
        Inicializa los valores de los colores RGB en 0.
        """
        self.r = 0
        self.g = 0
        self.b = 0

    def set(self, r, g, b):
        """
        Establece los valores de los colores RGB si cada valor está en el rango de 0 a 255.
        """
        if (r >= 0 and r <= 255) and (g >= 0 and g <= 255) and (b >= 0 and b <= 255):
            self.r = r
            self.g = g
            self.b = b

    def invert(self):
        """
        Invierte los valores de los colores RGB.
        """
        self.set(255 - self.r, 255 - self.g, 255 - self.b)

    def __str__(self):
        """
        Devuelve una representación en cadena del color RGB en formato RGB y hexadecimal.
        """
        return (
            f'RGB: ({self.r}, {self.g}, {self.b})\n' +
            f'HEX: 0x{self.r:02x}{self.g:02x}{self.b:02x}'
        )


def get_inverted_colors(file):
    """
    Lee un archivo que contiene valores de colores RGB, los invierte y devuelve una lista de los colores invertidos.
    """
    inverted = []
    f = open(file)
    for color in f.readlines():
        values = color.split(' ')
        rgb = RGB()
        rgb.set(int(values[0]), int(values[1]), int(values[2]))
        rgb.invert()
        inverted.append(rgb)
    f.close()
    
    return inverted


def main():
    """
    Función principal que lee un archivo de colores RGB desde la línea de comandos, invierte los colores y los imprime.
    """
    inverted = get_inverted_colors(argv[1])
    for color in inverted:
       print(f'{color}\n') 

    
if __name__ == '__main__':
    main()