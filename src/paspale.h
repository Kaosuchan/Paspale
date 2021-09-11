#ifndef PASPALE_H
#define PASPALE_H

#define HAHAHA

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __PASPALE
#define __PASPALE
#endif

typedef enum  {
  ERROR = -1,
  EXIT,
  TASK
} PaspaleSign;

typedef struct {
  PaspaleSign sign;
} PaspaleRequest, *Paspale;

typedef struct {
  PaspaleSign sign;
  int errorCode;
  char* errorMsg;
} PaspaleRequestOfError;

typedef struct {
  PaspaleSign sign;
  int exitValue;
} PaspaleRequestOfExit;

typedef Paspale (*PaspaleTask)();

typedef struct {
  PaspaleSign sign;
  PaspaleTask task;
} PaspaleRequestOfTask;

int PaspaleStart(Paspale);
Paspale PaspaleMakeRequestOfError(int, char*);
Paspale PaspaleMakeRequestOfExit(int);
Paspale PaspaleMakeRequestOfTask(PaspaleTask);

#ifdef __cplusplus
}
#endif

#endif