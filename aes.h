
#ifndef AES_H
#define AES_H

#include <stdint.h>

void key_expansion(uint8_t *expanded_key, uint8_t *key); 

void encrypt(uint8_t *out, uint8_t *in, uint8_t *expanded_key); 

void decrypt(uint8_t *out, uint8_t *in, uint8_t *expanded_key);

#endif
