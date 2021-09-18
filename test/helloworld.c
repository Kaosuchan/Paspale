#include "helloworld.h"
#include "stdio.h"

Paspale _HelloWorld();

Paspale HelloWorld() {
  return PaspaleGoto(_HelloWorld);
}

Paspale _HelloWorld() {
  printf("Hello World\n");
  return PaspaleExit();
}
