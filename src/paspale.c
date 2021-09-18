#include "paspale.h"

int PaspaleStart(Paspale paspale) {
  while(paspale.task) paspale = (*(paspale.task))();
  return 0;
}