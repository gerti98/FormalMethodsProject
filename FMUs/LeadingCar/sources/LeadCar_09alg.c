/* Algebraic */
#include "LeadCar_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void LeadCar_eqFunction_11(DATA* data, threadData_t *threadData);
extern void LeadCar_eqFunction_12(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
    LeadCar_eqFunction_11(data, threadData);

    LeadCar_eqFunction_12(data, threadData);
}
/* for continuous time variables */
int LeadCar_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  functionAlg_system0(data, threadData);

  LeadCar_function_savePreSynchronous(data, threadData);
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ALGEBRAICS);
#endif

  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif
