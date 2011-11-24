/*
 * Copyright (c) 2011 Javier Escalada Gómez
 * All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include "encrypted_strings.h"

int main(int argc, char **argv) {
	/*
	 * Create a buffer for each string before any instructions has been
	 * executed (just like declaring local variables)
	 */
	ES_CREATE_BUFFER(HELLO_WORLD, hw);
	ES_CREATE_BUFFER(FOO_BAR, fb);

	/*
	 * Decrypt the strings
	 */
	ES_DECRYPT(HELLO_WORLD, hw);
	ES_DECRYPT(FOO_BAR, fb);

	/*
	 * Use them
	 */
	puts(hw);
	puts(fb);
}
