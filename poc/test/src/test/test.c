/*
 ============================================================================
 Name        : test.c
 Author      : Lorand Kedves
 Version     :
 Copyright   : MondoAurora Foundation
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <dust.h>
#include <kernel.h>
#include <boot.h>

#include <test.h>

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

char* MSG = "This is my hello world message";

int testUnitInit() {
	bootTraceMsg("testUnitInit start");

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	Handle b = dustKernelMemAlloc(100);

	char s[100];
	dustKernelMemAccessBlock(b, 0, testStrlen(MSG) + 1, MSG, DUST_ACC_SET);
	dustKernelMemAccessBlock(b, 0, testStrlen(MSG) + 1, s, DUST_ACC_GET);

	dustKernelMemRelease(&b);

	bootTraceMsg(s);

//	dustGetReferredEntity(0);

//	Handle hEntity = dustCreateEntity(0);

	printf("sizeof int %d \n", sizeof (int) );
	printf("sizeof long %d \n", sizeof (long long) );


	bootTraceMsg("testUnitInit end");

	return EXIT_SUCCESS;
}


void bootTrace(Reference refUnit, Reference refMsg, const char* msg) {
	printf("trace - %d/%d ", (long) refUnit, (long) refMsg);
	printf(msg);
	printf("\n");

	fflush(stdout);
}

int testStrlen(const char* msg) {
	return strlen(msg);
}
