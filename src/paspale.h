#ifndef PASPALE_H
#define PASPALE_H

#ifdef __cplusplus
extern "C" {
#endif

struct Paspale;

typedef struct Paspale (*PaspaleFunction)();

typedef struct Paspale {
  PaspaleFunction task;
} Paspale;


int PaspaleStart(Paspale);

#define PaspaleGoto(task) ((Paspale){task})
#define PaspaleExit() ((Paspale){0})

#ifdef __cplusplus
}
#endif

#endif