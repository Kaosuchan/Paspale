#include <stdio.h>
#include "paspale.h"

Paspale paspaleRequest;
PaspaleRequestOfError paspaleRequestOfError;
PaspaleRequestOfExit paspaleRequestOfExit;
PaspaleRequestOfTask paspaleRequestOfTask;

int PaspaleStart(Paspale PaspaleBeginner) {
  paspaleRequestOfError.sign = ERROR;
  paspaleRequestOfExit.sign = EXIT;
  paspaleRequestOfTask.sign = TASK;
  paspaleRequest = PaspaleBeginner;
  while(paspaleRequest->sign == TASK)
    paspaleRequest = (*(((PaspaleRequestOfTask*)paspaleRequest)->task))();
  if(paspaleRequest->sign == ERROR) {
    fprintf(stderr, "%s\n", ((PaspaleRequestOfError*)paspaleRequest)->errorMsg);
    return ((PaspaleRequestOfError*)paspaleRequest)->errorCode;
  }
  else
    return ((PaspaleRequestOfExit*)paspaleRequest)->exitValue;
}

Paspale PaspaleMakeRequestOfError(int errorCode, char* errorMsg) {
  paspaleRequestOfError.errorCode = errorCode;
  paspaleRequestOfError.errorMsg = errorMsg;
  return (Paspale)&paspaleRequestOfError;
}

Paspale PaspaleMakeRequestOfExit(int exitCode) {
  paspaleRequestOfExit.exitValue = exitCode;
  return (Paspale)&paspaleRequestOfExit;
}

Paspale PaspaleMakeRequestOfTask(PaspaleTask task) {
  paspaleRequestOfTask.task = task;
  return (Paspale)&paspaleRequestOfTask;
}

