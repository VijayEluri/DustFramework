/*
 ============================================================================
 Name        : test.c
 Author      : Lorand Kedves
 Version     :
 Copyright   : MondoAurora Foundation
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "dust.h"
#include "kernel.h"

#include "test.h"
#include <string.h>

char* MSG = "This is my hello world message";

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	testTraceMsg("starting");

	Handle b = dustKernelMemAlloc(100);

	char s[100];
	dustKernelMemAccessBlock(b, 0, testStrlen(MSG) + 1, MSG, ACCESS_SET);
	dustKernelMemAccessBlock(b, 0, testStrlen(MSG) + 1, s, ACCESS_GET);

	dustKernelMemRelease(&b);

	testTraceMsg(s);

	dustGetReferredEntity(0);

	Handle hEntity = dustCreateEntity(0);

	testTraceMsg("entity created");

	return EXIT_SUCCESS;
}


void testTraceMsg(const char* msg) {
	printf("trace - ");
	printf(msg);
	printf("\n");

	fflush(stdout);
}

int testStrlen(const char* msg) {
	return strlen(msg);
}
