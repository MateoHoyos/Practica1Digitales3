#include <stdio.h>
#include <stdint.h>

#include "BitsToBytes.c"

void bytesEncode(unsigned char *F, int m, unsigned char *B) {
  int i, j, k;
  unsigned char a[256];

  // Convertir F a bits
  for (i = 0; i < 256; i++) {
    a[i] = 0;
    for (j = 0; j < m; j++) {
      a[i] |= (F[i] & (1 << (m - 1 - j))) << j;
    }
  }

  // Convertir bits a bytes
  BitsToBytes(a, 256, B);
}

int main() {
  // Ejemplo de uso
  unsigned char F[256] = {0}; // Inicializar F con valores
  int m = 8; // Ejemplo: m = 8 bits por símbolo
  unsigned char B[32]; // B tendrá 32 bytes para m = 8

  bytesEncode(F, m, B);

  // Imprimir los bytes
  for (int i = 0; i < 32; i++) {
    printf("%02x ", B[i]);
  }
  printf("\n");

  return 0;
}
