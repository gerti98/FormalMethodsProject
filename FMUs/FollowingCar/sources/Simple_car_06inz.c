/* Initialization */
#include "Simple_car_model.h"
#include "Simple_car_11mix.h"
#include "Simple_car_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Simple_car_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
speed = v0
*/
void Simple_car_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  data->localData[0]->realVars[5] /* speed variable */ = data->simulationInfo->realParameter[0] /* v0 PARAM */;
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
$outputAlias_speed = speed
*/
void Simple_car_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  data->localData[0]->realVars[0] /* $outputAlias_speed STATE(1) */ = data->localData[0]->realVars[5] /* speed variable */;
  TRACE_POP
}
extern void Simple_car_eqFunction_7(DATA *data, threadData_t *threadData);

extern void Simple_car_eqFunction_8(DATA *data, threadData_t *threadData);


/*
equation index: 5
type: SIMPLE_ASSIGN
x = x0
*/
void Simple_car_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  data->localData[0]->realVars[6] /* x variable */ = data->simulationInfo->realParameter[1] /* x0 PARAM */;
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
$outputAlias_x = x
*/
void Simple_car_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  data->localData[0]->realVars[1] /* $outputAlias_x STATE(1,$outputAlias_speed) */ = data->localData[0]->realVars[6] /* x variable */;
  TRACE_POP
}
OMC_DISABLE_OPT
void Simple_car_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Simple_car_eqFunction_1(data, threadData);
  Simple_car_eqFunction_2(data, threadData);
  Simple_car_eqFunction_7(data, threadData);
  Simple_car_eqFunction_8(data, threadData);
  Simple_car_eqFunction_5(data, threadData);
  Simple_car_eqFunction_6(data, threadData);
  TRACE_POP
}

int Simple_car_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Simple_car_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No Simple_car_functionInitialEquations_lambda0 function */

int Simple_car_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

