/********************************************************************
* @author Andrea Calero Caro
* Alu: 0101202952
* Práctica 3: Cifrado de Chacha20
* Asignatura: Seguridad en Sistemas Informáticos
* Universidad de La Laguna 
********************************************************************/

#include <stdio.h>
#include "chacha20.h"

/*
 * Programa principal declaro la clave, el nonce y el mensaje original
 */
int main(int argc, char **argv) {
  int i;

  // Clave de 256 bits, 64 *4 =256
  uint8_t key[] = {
    0x00, 0x01, 0x02, 0x03,
    0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0a, 0x0b,
    0x0c, 0x0d, 0x0e, 0x0f,
    0x10, 0x11, 0x12, 0x13,
    0x14, 0x15, 0x16, 0x17,
    0x18, 0x19, 0x1a, 0x1b,
    0x1c, 0x1d, 0x1e, 0x1f
  };

  // Nonce de 96 bits 24*4
  uint8_t nonce[] = {
    0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00
  };

  // Contador 32 bits 
  uint8_t contador[]={
    0x10, 0x00, 0x00, 0x00
  };

  // Estado inicial o input array 128-bit, 32 *4
  uint8_t input[] = {
    0x2a, 0x01, 0x64, 0x69,
    0x65, 0x73, 0x20, 0x61,
    0x3e, 0x64, 0x20, 0x47,
    0x65, 0x6e, 0x74, 0x6c,
    /*
    0x4c, 0x61, 0x64, 0x69, 0x65, 0x73, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x47, 0x65, 0x6e, 0x74, 0x6c,
    0x65, 0x6d, 0x65, 0x6e, 0x20, 0x6f, 0x66, 0x20, 0x74, 0x68, 0x65, 0x20, 0x63, 0x6c, 0x61, 0x73,
    0x73, 0x20, 0x6f, 0x66, 0x20, 0x27, 0x39, 0x39, 0x3a, 0x20, 0x49, 0x66, 0x20, 0x49, 0x20, 0x63,
    0x6f, 0x75, 0x6c, 0x64, 0x20, 0x6f, 0x66, 0x66, 0x65, 0x72, 0x20, 0x79, 0x6f, 0x75, 0x20, 0x6f,
    0x6e, 0x6c, 0x79, 0x20, 0x6f, 0x6e, 0x65, 0x20, 0x74, 0x69, 0x70, 0x20, 0x66, 0x6f, 0x72, 0x20,
    0x74, 0x68, 0x65, 0x20, 0x66, 0x75, 0x74, 0x75, 0x72, 0x65, 0x2c, 0x20, 0x73, 0x75, 0x6e, 0x73,
    0x63, 0x72, 0x65, 0x65, 0x6e, 0x20, 0x77, 0x6f, 0x75, 0x6c, 0x64, 0x20, 0x62, 0x65, 0x20, 0x69,
    0x74, 0x2e*/ //114 palabras
  };

  uint8_t encrypt[16];
  uint8_t decrypt[16];

  // Llamada a la función para encriptar el mensaje
  ChaCha20XOR(key, 1, nonce, input, encrypt, 16);
  // Llamada a la función para desencriptar el mensaje
  ChaCha20XOR(key, 1, nonce, encrypt, decrypt, 16);

  printf("\nKey:");
  for(i = 0; i < 32; i++) {
      if (!(i % 16)) {
        printf("\n");
      }
      printf("%02x ", key[i]);
    }

  printf("\n\nNonce:\n");
  for (i = 0; i < 12; i++) {
    printf("%02x ", nonce[i]);
  }

  printf("\n\nContador:\n");
  for(i=0; i < 4;i++){
    printf("%02x ", contador[i]);
  }

  printf("\n\nEstado inicial:");
  for (i = 0; i < 16; i++) {  //114
    if (!(i % 16)) {
      printf("\n");
    }
      printf("%02x ", input[i]);
  }

  printf("\n\nEncrypted:");
  for (i = 0; i < 16; i++) {  //114
    if (!(i % 16)) {
      printf("\n");
    }
    printf("%02x ", encrypt[i]);
  }

  printf("\n\nDecrypted:");
    for (i = 0; i < 16; i++) { //114
      if (!(i % 16)) {
        printf("\n");
      }
      printf("%02x ", decrypt[i]);
    }

  printf("\n");
  return 0;
}