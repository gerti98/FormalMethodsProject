/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "Simple_car_model.h"
#include "simulation/solver/events.h"



/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int Simple_car_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->localData[0]->realVars[4] /* accel variable */ = data->simulationInfo->inputVars[0];
  
  TRACE_POP
  return 0;
}

int Simple_car_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->realVarsData[4].attribute.start;
  
  TRACE_POP
  return 0;
}

int Simple_car_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->realVarsData[4].attribute.start = data->simulationInfo->inputVars[0];
  
  TRACE_POP
  return 0;
}

int Simple_car_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  names[0] = (char *) data->modelData->realVarsData[4].info.name;
  
  TRACE_POP
  return 0;
}

int Simple_car_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int Simple_car_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Simple_car_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->outputVars[0] = data->localData[0]->realVars[5] /* speed variable */;
  data->simulationInfo->outputVars[1] = data->localData[0]->realVars[6] /* x variable */;
  
  TRACE_POP
  return 0;
}

int Simple_car_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 7
type: SIMPLE_ASSIGN
$DER.$outputAlias_x = $outputAlias_speed
*/
void Simple_car_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  data->localData[0]->realVars[3] /* der($outputAlias_x) STATE_DER */ = data->localData[0]->realVars[0] /* $outputAlias_speed STATE(1) */;
  TRACE_POP
}
/*
equation index: 8
type: SIMPLE_ASSIGN
$DER.$outputAlias_speed = accel
*/
void Simple_car_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  data->localData[0]->realVars[2] /* der($outputAlias_speed) STATE_DER */ = data->localData[0]->realVars[4] /* accel variable */;
  TRACE_POP
}
/*
equation index: 9
type: SIMPLE_ASSIGN
speed = $outputAlias_speed
*/
void Simple_car_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  data->localData[0]->realVars[5] /* speed variable */ = data->localData[0]->realVars[0] /* $outputAlias_speed STATE(1) */;
  TRACE_POP
}
/*
equation index: 10
type: SIMPLE_ASSIGN
x = $outputAlias_x
*/
void Simple_car_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  data->localData[0]->realVars[6] /* x variable */ = data->localData[0]->realVars[1] /* $outputAlias_x STATE(1,$outputAlias_speed) */;
  TRACE_POP
}

OMC_DISABLE_OPT
int Simple_car_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Simple_car_functionLocalKnownVars(data, threadData);
  Simple_car_eqFunction_7(data, threadData);

  Simple_car_eqFunction_8(data, threadData);

  Simple_car_eqFunction_9(data, threadData);

  Simple_car_eqFunction_10(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int Simple_car_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void Simple_car_eqFunction_7(DATA* data, threadData_t *threadData);
extern void Simple_car_eqFunction_8(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
    Simple_car_eqFunction_7(data, threadData);

    Simple_car_eqFunction_8(data, threadData);
}

int Simple_car_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Simple_car_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "Simple_car_12jac.h"
#include "Simple_car_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Simple_car_callback = {
   NULL,    /* performSimulation */
   NULL,    /* performQSSSimulation */
   NULL,    /* updateContinuousSystem */
   Simple_car_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   Simple_car_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   Simple_car_initializeDAEmodeData,
   Simple_car_functionODE,
   Simple_car_functionAlgebraics,
   Simple_car_functionDAE,
   Simple_car_functionLocalKnownVars,
   Simple_car_input_function,
   Simple_car_input_function_init,
   Simple_car_input_function_updateStartValues,
   Simple_car_data_function,
   Simple_car_output_function,
   Simple_car_setc_function,
   Simple_car_function_storeDelayed,
   Simple_car_updateBoundVariableAttributes,
   Simple_car_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   Simple_car_functionRemovedInitialEquations,
   Simple_car_updateBoundParameters,
   Simple_car_checkForAsserts,
   Simple_car_function_ZeroCrossingsEquations,
   Simple_car_function_ZeroCrossings,
   Simple_car_function_updateRelations,
   Simple_car_zeroCrossingDescription,
   Simple_car_relationDescription,
   Simple_car_function_initSample,
   Simple_car_INDEX_JAC_A,
   Simple_car_INDEX_JAC_B,
   Simple_car_INDEX_JAC_C,
   Simple_car_INDEX_JAC_D,
   Simple_car_INDEX_JAC_F,
   Simple_car_initialAnalyticJacobianA,
   Simple_car_initialAnalyticJacobianB,
   Simple_car_initialAnalyticJacobianC,
   Simple_car_initialAnalyticJacobianD,
   Simple_car_initialAnalyticJacobianF,
   Simple_car_functionJacA_column,
   Simple_car_functionJacB_column,
   Simple_car_functionJacC_column,
   Simple_car_functionJacD_column,
   Simple_car_functionJacF_column,
   Simple_car_linear_model_frame,
   Simple_car_linear_model_datarecovery_frame,
   Simple_car_mayer,
   Simple_car_lagrange,
   Simple_car_pickUpBoundsForInputsInOptimization,
   Simple_car_setInputData,
   Simple_car_getTimeGrid,
   Simple_car_symbolicInlineSystem,
   Simple_car_function_initSynchronous,
   Simple_car_function_updateSynchronous,
   Simple_car_function_equationsSynchronous,
   Simple_car_inputNames,
   Simple_car_dataReconciliationInputNames,
   Simple_car_read_input_fmu,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "Complex"
#define _OMC_LIT_RESOURCE_0_dir_data "/home/maurizio/.openmodelica/libraries/Complex 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,7,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,61,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "LeadCar"
#define _OMC_LIT_RESOURCE_1_dir_data "/home/maurizio/OM"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,7,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,17,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "Modelica"
#define _OMC_LIT_RESOURCE_2_dir_data "/home/maurizio/.openmodelica/libraries/Modelica 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,8,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,62,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "ModelicaReference"
#define _OMC_LIT_RESOURCE_3_dir_data "/usr/lib/omlibrary/ModelicaReference"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,17,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,36,_OMC_LIT_RESOURCE_3_dir_data);

#define _OMC_LIT_RESOURCE_4_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_4_dir_data "/home/maurizio/.openmodelica/libraries/ModelicaServices 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_4_name,16,_OMC_LIT_RESOURCE_4_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_4_dir,70,_OMC_LIT_RESOURCE_4_dir_data);

#define _OMC_LIT_RESOURCE_5_name_data "Simple_car"
#define _OMC_LIT_RESOURCE_5_dir_data "/home/maurizio/OM"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_5_name,10,_OMC_LIT_RESOURCE_5_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_5_dir,17,_OMC_LIT_RESOURCE_5_dir_data);

#define _OMC_LIT_RESOURCE_6_name_data "quadcopter"
#define _OMC_LIT_RESOURCE_6_dir_data "/home/maurizio/OM"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_6_name,10,_OMC_LIT_RESOURCE_6_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_6_dir,17,_OMC_LIT_RESOURCE_6_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,14,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_4_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_4_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_5_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_5_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_6_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_6_dir)}};
void Simple_car_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &Simple_car_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "Simple_car";
  data->modelData->modelFilePrefix = "Simple_car";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/maurizio/OM";
  data->modelData->modelGUID = "{283b2ff0-383c-463e-8bdb-62f24905c514}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  data->modelData->runTestsuite = 0;
  
  data->modelData->nStates = 2;
  data->modelData->nVariablesReal = 7;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 2;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 1;
  data->modelData->nOutputVars = 2;
  
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  
  GC_asprintf(&data->modelData->modelDataXml.fileName, "%s/Simple_car_info.json", data->modelData->resourcesDir);
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 11;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 5;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  
  data->modelData->nDelayExpressions = 0;
  
  data->modelData->nClocks = 0;
  data->modelData->nSubClocks = 0;
  
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
  data->modelData->nSetcVars = 0;
  data->modelData->ndataReconVars = 0;
  data->modelData->linearizationDumpLanguage =
  OMC_LINEARIZE_DUMP_LANGUAGE_MODELICA;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

