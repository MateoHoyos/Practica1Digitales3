#include <stdio.h>
#include <stdint.h>

// Función para convertir una cadena de bits a un arreglo de bytes
void BitsToBytes(uint8_t *b, uint8_t *B, uint32_t l) {
  // Inicializar el arreglo de bytes
  for (uint32_t i = 0; i < l; i++) {
    B[i] = 0;
  }

  // Bucle principal para procesar los bits
  for (uint32_t i = 0; i < 8 * l; i++) {
    // Calcular el índice del byte actual
    uint32_t j = i / 8;

    // Calcular la posición del bit dentro del byte
    uint32_t k = i % 8;

    // Agregar el valor del bit a la posición actual del byte
    B[j] |= (b[i] << k);
  }
}

/*
int main() {
  // Definir la cadena de bits
  uint8_t b[] = {0x01, 0x00, 0x11, 0x00, 0x00, 0x10, 0x11, 0x10};
  uint32_t l = sizeof(b) / sizeof(b[0]);

  // Arreglo para almacenar los bytes
  uint8_t B[l];

  // Convertir la cadena de bits a bytes
  BitsToBytes(b, B, l);

  // Imprimir los bytes
  for (uint32_t i = 0; i < l; i++) {
    printf("%02x ", B[i]);
  }

  printf("\n");

  return 0;
}
*/