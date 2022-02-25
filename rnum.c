#include <stdio.h>
#include <limits.h>
#include <openssl/rand.h>

int main(int argc, char *argv[]) {
	unsigned int bytes = sizeof(unsigned int);
	unsigned char buf[bytes];
	unsigned int max = atoi(argv[1]);
	unsigned int randmax = UINT_MAX - (UINT_MAX - max + 1) % max;
	unsigned int n = 0;
	while(n == 0 || n > randmax) {
		RAND_bytes(buf, bytes);
		n = buf[0];
		for(unsigned int byte = 1; byte < bytes; byte = byte + 1) {
			unsigned int factor=256;
			for(unsigned int pow = 2; pow <= byte; pow = pow + 1) {
				factor = factor * factor;
			}
			n = n + factor * buf[byte];
		}
	}
	printf("%u\n", n % max + 1);
}
