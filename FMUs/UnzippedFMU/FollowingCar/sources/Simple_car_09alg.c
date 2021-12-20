/* Algebraic */
#include "Simple_car_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void Simple_car_eqFunction_9(DATA* data, threadData_t *threadData);
extern void Simple_car_eqFunction_10(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
    Simple_car_eqFunction_9(data, threadData);

    Simple_car_eqFunction_10(data, threadData);
}
/* for continuous time variables */
int Simple_car_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  functionAlg_system0(data, threadData);

  Simple_car_function_savePreSynchronous(data, threadData);
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ALGEBRAICS);
#endif

  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif
