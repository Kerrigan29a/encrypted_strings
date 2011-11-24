#include <iostream>
#include "encrypted_strings.h"

int main(int argc, char **argv) {

	/*
	 * Decrypt the strings and use them
	 */
	ES_DECRYPT(HELLO_WORLD, hw);
	std::cout << hw << std::endl;

	ES_DECRYPT(FOO_BAR, fb);
	std::cout << fb << std::endl;
}
