/* External objects file */
#include "Simple_car_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Simple_car_callExternalObjectDestructors(DATA *data, threadData_t *threadData)
{
  if(data->simulationInfo->extObjs)
  {
    free(data->simulationInfo->extObjs);
    data->simulationInfo->extObjs = 0;
  }
}
#if defined(__cplusplus)
}
#endif

