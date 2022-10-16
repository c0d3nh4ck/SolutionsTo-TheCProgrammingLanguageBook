#include <stdio.h>

#define swap(t, x, y) {t temp; temp = x; x = y; y = temp;}

int main()
{
    int ix, iy;
	double dx, dy;
	char *px, *py;

	ix = 42;
	iy = 69;
	printf("integers before swap: %d and %d\n", ix, iy);
	swap(int, ix, iy);
	printf("integers after swap: %d and %d\n", ix, iy);

	px = "hello";
	py = "world";
	printf("pointers before swap: %s and %s\n", px, py);
	swap(char *, px, py);
	printf("integers after swap: %s and %s\n", px, py);

	return 0;
}
