/*
 * Copyright (c) 2011 Javier Escalada Gómez
 * All rights reserved.
 */

#ifndef __ENCRYPTED_STRINGS__
#define __ENCRYPTED_STRINGS__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __cplusplus
#include <stdlib.h>
#include <assert.h>
#endif


/*
 * Export the variables related to the encrypted text strings
 */
#define STR(id, len, ...) \
extern char es_##id[]; \
extern unsigned es_len_##id;
#include "encrypted_strings.def"
#undef STR

#ifndef __cplusplus

#define ES_CREATE_BUFFER(id, buffer) char buffer[es_len_##id]

#define ES_DECRYPT(id, buffer) do { \
	assert(buffer != NULL); \
	_es_decrypt(es_##id, es_len_##id, buffer); \
} while (0 /* CONST COND */)

#else

#define ES_DECRYPT(id, buffer) \
char buffer[es_len_##id]; \
_es_decrypt(es_##id, es_len_##id, buffer)

#endif


char * _es_decrypt(char encrypted_string[], unsigned len, char *buffer);

#ifdef __cplusplus
}
#endif

#endif /*__ENCRYPTED_STRINGS__*/
