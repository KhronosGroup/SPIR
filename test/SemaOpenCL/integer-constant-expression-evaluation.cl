// RUN: %clang_cc1 %s -verify -fsyntax-only
// expected-no-diagnostics

typedef unsigned int size_t;
#define DLNUM2SYM_(p,x)	p##x
#define DLNUM2SYM(p,x)	DLNUM2SYM_(p,x)

#define CTMUST(x)	struct DLNUM2SYM(ctmust,__LINE__)		\
			{ int condition_check[(x)?1:-1]; };

#define CTMUST_LAY(a,ca,o,s)	CTMUST(((size_t)(&((a*)0)->ca))==(o) \
									   && sizeof(((a*)0)->ca)==(s))

typedef struct
{
	char	d[64];
	short 	b[2];
	char	o,p;
	short 	c,s,l;
	short 	x,y;
} tFtPoint2;

CTMUST(sizeof(tFtPoint2)==80);
CTMUST_LAY(tFtPoint2,d,0,64);
