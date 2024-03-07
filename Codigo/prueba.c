#include <stdint.h>

#define FIELD_MODULUS 768 /* Suponiendo que FIELD_MODULUS es un valor definido en parameters.h */

/* Suponiendo que `a_hat` es una matriz de tamaño adecuado ya definida */
/* Suponiendo que `parameters` es una estructura que contiene los parámetros necesarios */

uint16_t a_hat[SIZE]; /* Tamaño adecuado para a_hat */

uint16_t d1, d2;
int sampled_coefficients = 0;

for (int i = 0; i < size_of_bytes_array; i += 3) {
    uint16_t b = bytes[i];
    uint16_t b1 = bytes[i + 1];
    uint16_t b2 = bytes[i + 2];

    d1 = b + (256 * (b1 % 16));
    d2 = (b1 / 16) + (16 * b2);

    if (d1 < FIELD_MODULUS && sampled_coefficients < sizeof(a_hat) / sizeof(a_hat[0])) {
        a_hat[sampled_coefficients] = d1;
        sampled_coefficients++;
    }

    if (d2 < FIELD_MODULUS && sampled_coefficients < sizeof(a_hat) / sizeof(a_hat[0])) {
        a_hat[sampled_coefficients] = d2;
        sampled_coefficients++;
    }
}

if (sampled_coefficients == sizeof(a_hat) / sizeof(a_hat[0])) {
    /* Procesamiento completo, la matriz a_hat está llena */
} else {
    /* No se completó la generación de coeficientes de manera correcta */
}
