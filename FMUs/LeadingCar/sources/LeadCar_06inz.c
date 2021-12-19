/* Initialization */
#include "LeadCar_model.h"
#include "LeadCar_11mix.h"
#include "LeadCar_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void LeadCar_functionInitialEquations_0(DATA *data, threadData_t *threadData);
extern void LeadCar_eqFunction_8(DATA *data, threadData_t *threadData);

extern void LeadCar_eqFunction_9(DATA *data, threadData_t *threadData);


/*
equation index: 3
type: SIMPLE_ASSIGN
simple_car.speed = simple_car.v0
*/
void LeadCar_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  data->localData[0]->realVars[0] /* simple_car.speed STATE(1,accel) */ = data->simulationInfo->realParameter[0] /* simple_car.v0 PARAM */;
  TRACE_POP
}
extern void LeadCar_eqFunction_11(DATA *data, threadData_t *threadData);

extern void LeadCar_eqFunction_10(DATA *data, threadData_t *threadData);


/*
equation index: 6
type: SIMPLE_ASSIGN
simple_car.x = simple_car.x0
*/
void LeadCar_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  data->localData[0]->realVars[1] /* simple_car.x STATE(1,simple_car.speed) */ = data->simulationInfo->realParameter[1] /* simple_car.x0 PARAM */;
  TRACE_POP
}
extern void LeadCar_eqFunction_12(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void LeadCar_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  LeadCar_eqFunction_8(data, threadData);
  LeadCar_eqFunction_9(data, threadData);
  LeadCar_eqFunction_3(data, threadData);
  LeadCar_eqFunction_11(data, threadData);
  LeadCar_eqFunction_10(data, threadData);
  LeadCar_eqFunction_6(data, threadData);
  LeadCar_eqFunction_12(data, threadData);
  TRACE_POP
}

int LeadCar_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  LeadCar_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No LeadCar_functionInitialEquations_lambda0 function */

int LeadCar_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

