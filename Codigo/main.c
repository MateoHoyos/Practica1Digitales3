#include <stdio.h>
#include <stdint.h>

const int q = 3329;
const int n = 256;


int pseudoaleatorio(uint32_t x) {
    unsigned int seed = 123456789; // Semilla de 32 bits conocida
    srand(seed); // Establecer la semilla inicial

    // Generar números pseudoaleatorios
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", rand()); // Imprimir numero pseudoaleatorio
    }
    return 0;
}


//*******************Algortimo 2
void BitsToBytes(uint8_t *b, uint8_t *B, uint32_t l) {

  for (uint32_t i = 0; i < l; i++) {
    B[i] = 0;
  }

  for (uint32_t i = 0; i < 8 * l; i++) {
    uint32_t j = i / 8;
    uint32_t k = i % 8;
    B[j] |= (b[i] << k);
  }
}


//*******************Algortimo 3
void bytes_to_bits(unsigned char *bytes, int num_bytes, unsigned char *bits) {
  for (int i = 0; i < num_bytes; i++) {
    for (int j = 0; j < 8; j++) {
      bits[8 * i + j] = bytes[i] & (1 << (7 - j));
    }
  }
}


//*******************Algortimo 4
void bytesEncode(unsigned char *F, int m, unsigned char *B) {
  int i, j, k;
  unsigned char a[256];

  for (i = 0; i < 256; i++) {
    a[i] = 0;
    for (j = 0; j < m; j++) {
      a[i] |= (F[i] & (1 << (m - 1 - j))) << j;
    }
  }

  BitsToBytes(a, 256, B);
}

//*******************Algortimo 5




//*******************Algortimo6
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
   
   return 0;
}