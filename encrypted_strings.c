/*
 * Copyright (c) 2011 Javier Escalada Gómez
 * All rights reserved.
 */

#include "encrypted_strings.h"

/* Embeds the encrypted text strings */
#define STR(id, len, ...) char es_##id[] = __VA_ARGS__;
#include "encrypted_strings.def"
#undef STR

/* Embeds the sizes of the encrypted text strings */
#define STR(id, len, ...) unsigned es_len_##id = len;
#include "encrypted_strings.def"
#undef STR

char * _es_decrypt(char encrypted_string[], unsigned len, char *buffer) {
	unsigned register i;
	for (i = 0; i < len; ++i) {
		*(buffer + i) = encrypted_string[i] ^ len;
	}
	*(buffer + len) = 0;
	return buffer;
}
