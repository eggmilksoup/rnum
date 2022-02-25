#include <stdio.h>
#include <limits.h>
#include <openssl/rand.h>

int main(int argc, char *argv[]) {
	uint bytes = sizeof(uint);
	unsigned char buf[bytes];
	uint max = atoi(argv[1]);
	uint randmax = UINT_MAX - (UINT_MAX - max + 1) % max;
	uint n = 0;
	while(n == 0 || n > randmax) {
		RAND_bytes(buf, bytes);
		n = buf[0];
		for(uint byte = 1; byte < bytes; byte = byte + 1) {
			uint factor=256;
			for(uint pow = 2; pow <= byte; pow = pow + 1) {
				factor = factor * factor;
			}
			n = n + factor * buf[byte];
		}
	}
	printf("%u\n", n % max + 1);
}
