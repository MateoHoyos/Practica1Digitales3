#include <stdio.h>
#include <stdint.h>

const int q = 3329;

// Función para generar un byte aleatorio
unsigned char random_byte() {
  return (unsigned char)rand();
}

// Función para implementar el algoritmo SampleNTT
void sample_ntt(unsigned char *b, unsigned char *a) {
  int i = 0;
  int j = 0;
  uint16_t d1, d2;
  uint16_t b, b1, b2;

  while (j < 256) {

    b = b[i];
    b1 = b[i + 1];
    b2 = b[i + 2];
    d1 = b + (256 * (b1 % 16));
    d2 = (b1 / 16) + (16 * b2);

    if (d1 < q) {
      a[j] = d1;
      j++;
    }
    if (d2 < q && j < 256) {
      a[j] = d2;
      j++;
    }
    i += 3;
  }
}

int main() {
  // Generar una secuencia de bytes aleatorios
  unsigned char b[256];
  for (int i = 0; i < 256; i++) {
    b[i] = random_byte();
  }

  // Generar un elemento aleatorio de Tq
  unsigned char a[256];
  sample_ntt(b, a);

  // Imprimir el elemento aleatorio
  for (int i = 0; i < 256; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
