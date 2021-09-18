#include "helloworld.h"
#include "stdio.h"

Paspale _HelloWorld();

Paspale HelloWorld() {
  PaspaleGoto(_HelloWorld);
}

Paspale _HelloWorld() {
  printf("Hello World\n");
  PaspaleExit();
}