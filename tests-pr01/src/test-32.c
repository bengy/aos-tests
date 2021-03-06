/*
 * test-32.c
 * Copyright (C) 2015 benjamin <benjamin@assus>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include "gtthread.h"
void* thr(void *in) {
  return NULL;
}

int main() {
  printf("test4b. Should print 'Success'.\n");

  gtthread_init(50000L);
  gtthread_t t;
  gtthread_create( &t, thr, NULL);
  if(gtthread_equal(gtthread_self(), t)) {
    printf("Failure.");
  } else {
    printf("Success");
  }
  return EXIT_SUCCESS;
}

