#include "helloworld.h"
#include "stdio.h"

Paspale _HelloWorld();

Paspale HelloWorld() {
  return PaspaleMakeRequestOfTask(_HelloWorld);
}

Paspale _HelloWorld() {
  printf("Hello World\n");
  return PaspaleMakeRequestOfExit(0);
}