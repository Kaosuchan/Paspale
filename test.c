#include <stdio.h>
#include "paspale.h"
#include "test/helloworld.h"

int main(int argc, char** argv) {
  PaspaleStart(HelloWorld());
  return 0;
}