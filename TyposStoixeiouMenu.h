#ifndef __TSMENU__
#define __TSMENU__
#include <stdio.h>
#include "extra.h"

typedef struct Komvos {
	char * name; 	// Name of Category or Plate
	int Category;	// 0 if Plate, 1 if Category
	float Price;	// Valid only if Plate
} TStoixeiouMenu;

void TSSetValue(TStoixeiouMenu *Lhs, TStoixeiouMenu Rhs); // Lhs = Rhs
int TSPrintValue(FILE *out, TStoixeiouMenu V);
int TSReadValue(FILE *in, TStoixeiouMenu * V);
#endif
