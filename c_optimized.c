#include <stdio.h>

// a,b -> b , a % b

int gcd(int a, int b) {
	// if b is not 0
	
	while (b > 1) {
	int t;

	a = t;
	a = b;
	b = a % t;

	printf("a is now %d,b is now %d", a, b);
	want_contin();
	}
	return 0;
}

int main(int argc, char **argv) {
	    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int g = gcd(a, b);
    printf("gcd(%d, %d) = %d\n", a, b, g);

	return 0;
}

int want_contin (void) {
	char conti;
	printf("Continue? [Y,n]\n");
	scanf(" %c", &conti);
	if (conti=='Y' || conti=='y'){
		return 0;
	}	else {
		return 1;
	}
	
}
