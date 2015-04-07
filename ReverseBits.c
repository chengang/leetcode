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
	unsigned int a;
};

uint32_t reverseBits(uint32_t n) {
	union xx xxIn;
	xxIn.a = (unsigned int) n;
	union xx xxOut;
	xxOut.b.a1 = xxIn.b.a32;
	xxOut.b.a2 = xxIn.b.a31;
	xxOut.b.a3 = xxIn.b.a30;
	xxOut.b.a4 = xxIn.b.a29;
	xxOut.b.a5 = xxIn.b.a28;
	xxOut.b.a6 = xxIn.b.a27;
	xxOut.b.a7 = xxIn.b.a26;
	xxOut.b.a8 = xxIn.b.a25;
	xxOut.b.a9 = xxIn.b.a24;
	xxOut.b.a10 = xxIn.b.a23;
	xxOut.b.a11 = xxIn.b.a22;
	xxOut.b.a12 = xxIn.b.a21;
	xxOut.b.a13 = xxIn.b.a20;
	xxOut.b.a14 = xxIn.b.a19;
	xxOut.b.a15 = xxIn.b.a18;
	xxOut.b.a16 = xxIn.b.a17;
	xxOut.b.a17 = xxIn.b.a16;
	xxOut.b.a18 = xxIn.b.a15;
	xxOut.b.a19 = xxIn.b.a14;
	xxOut.b.a20 = xxIn.b.a13;
	xxOut.b.a21 = xxIn.b.a12;
	xxOut.b.a22 = xxIn.b.a11;
	xxOut.b.a23 = xxIn.b.a10;
	xxOut.b.a24 = xxIn.b.a9;
	xxOut.b.a25 = xxIn.b.a8;
	xxOut.b.a26 = xxIn.b.a7;
	xxOut.b.a27 = xxIn.b.a6;
	xxOut.b.a28 = xxIn.b.a5;
	xxOut.b.a29 = xxIn.b.a4;
	xxOut.b.a30 = xxIn.b.a3;
	xxOut.b.a31 = xxIn.b.a2;
	xxOut.b.a32 = xxIn.b.a1;
	return xxOut.a;
}
