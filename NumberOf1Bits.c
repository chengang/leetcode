#include <stdio.h>

struct foo
{
	unsigned int a1:1;
	unsigned int a2:1;
	unsigned int a3:1;
	unsigned int a4:1;
	unsigned int a5:1;
	unsigned int a6:1;
	unsigned int a7:1;
	unsigned int a8:1;
	unsigned int a9:1;
	unsigned int a10:1;
	unsigned int a11:1;
	unsigned int a12:1;
	unsigned int a13:1;
	unsigned int a14:1;
	unsigned int a15:1;
	unsigned int a16:1;
	unsigned int a17:1;
	unsigned int a18:1;
	unsigned int a19:1;
	unsigned int a20:1;
	unsigned int a21:1;
	unsigned int a22:1;
	unsigned int a23:1;
	unsigned int a24:1;
	unsigned int a25:1;
	unsigned int a26:1;
	unsigned int a27:1;
	unsigned int a28:1;
	unsigned int a29:1;
	unsigned int a30:1;
	unsigned int a31:1;
	unsigned int a32:1;
};

union xx{
	struct foo b;
	int a;
};

int main()
{
	int c = 3;
	union xx uxx;
	uxx.a = c;
	printf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d"
			, uxx.b.a1
			, uxx.b.a2
			, uxx.b.a3
			, uxx.b.a4
			, uxx.b.a5
			, uxx.b.a6
			, uxx.b.a7
			, uxx.b.a8
			, uxx.b.a9
			, uxx.b.a10
			, uxx.b.a11
			, uxx.b.a12
			, uxx.b.a13
			, uxx.b.a14
			, uxx.b.a15
			, uxx.b.a16
			, uxx.b.a17
			, uxx.b.a18
			, uxx.b.a19
			, uxx.b.a20
			, uxx.b.a21
			, uxx.b.a22
			, uxx.b.a23
			, uxx.b.a24
			, uxx.b.a25
			, uxx.b.a26
			, uxx.b.a27
			, uxx.b.a28
			, uxx.b.a29
			, uxx.b.a30
			, uxx.b.a31
			, uxx.b.a32
			);
}


