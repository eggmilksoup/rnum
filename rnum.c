#include <stdio.h>
#include <limits.h>
#include <openssl/rand.h>

int main(int argc, char *argv[]) {
	if(argc != 2)
	{
		fprintf(stderr, "usage: %s max\n", argv[0]);
		return 1;
	}
	int bytes = sizeof(long long);
	unsigned char buf[bytes];
	long long max = strtoll(argv[1], NULL, 10);
	if(max < 1)
	{
		fprintf(stderr, "max must be a positive integer\n");
		return 1;
	}
	long long randmax = LLONG_MAX - (LLONG_MAX - max + 1) % max;
	long long n = 0;
	while(n == 0 || n > randmax)
	{
		RAND_bytes(buf, bytes);
		n = buf[0];
		for(int byte = 1; byte < bytes; byte = byte + 1)
		{
			int factor=256;
			for(int pow = 2; pow <= byte; pow = pow + 1)
				factor = factor * factor;

			n = n + factor * buf[byte];
		}
	}
	printf("%lld\n", n % max + 1);
}
