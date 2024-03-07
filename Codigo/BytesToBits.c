#include <stdio.h>

void bytes_to_bits(unsigned char *bytes, int num_bytes, unsigned char *bits) {
  for (int i = 0; i < num_bytes; i++) {
    for (int j = 0; j < 8; j++) {
      bits[8 * i + j] = bytes[i] & (1 << (7 - j));
    }
  }
}

int main() {
  // Ejemplo de uso
  unsigned char bytes[] = {0xAB, 0xCD, 0xEF};
  unsigned char bits[24];

  bytes_to_bits(bytes, 3, bits);

  // Imprimir los bits
  for (int i = 0; i < 24; i++) {
    printf("%d", bits[i]);
  }
  printf("\n");

  return 0;
}
