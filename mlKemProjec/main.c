#include "mlkem.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    // Arreglo de bits de entrada
        uint8_t b[] = {0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1}; // ejemplo de arreglo de bits

        // Calcular la longitud del arreglo de bits
        size_t bit_length = sizeof(b) / sizeof(b[0]);

        // Calcular la longitud del arreglo de bytes
        size_t byte_length = (bit_length + 7) / 8; // Redondea hacia arriba la división entera de bit_length por 8
        // Arreglo de bytes de salida
        uint8_t B[byte_length];
        printf("%d",byte_length);
        // Convertir el arreglo de bits al arreglo de bytes
        bits_to_bytes(b, bit_length, B, byte_length);

        // Imprimir el arreglo de bytes resultante
        printf("Arreglo de bytes resultante:\n");
        for (size_t i = 0; i < byte_length; i++) {
            printf("%d\n", B[i]);
        }
        printf("\n");

        return 0;

        */

       const size_t KEY_LENGTH_BYTES = 32; // 32 bytes
       uint8_t key[KEY_LENGTH_BYTES];

       // Generar la clave aleatoria
       generate_random_key(key, KEY_LENGTH_BYTES);

       // Imprimir la clave aleatoria generada
       printf("Clave aleatoria generada (en bytes):\n");
       for (size_t i = 0; i < KEY_LENGTH_BYTES; ++i) {
           printf("%0x ", key[i]);
       }
       printf("\n");
       return 0;
}
