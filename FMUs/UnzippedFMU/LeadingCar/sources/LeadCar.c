/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "LeadCar_model.h"
#include "simulation/solver/events.h"



/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int LeadCar_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int LeadCar_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int LeadCar_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int LeadCar_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int LeadCar_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int LeadCar_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int LeadCar_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->outputVars[0] = data->localData[0]->realVars[4] /* accel variable */;
  data->simulationInfo->outputVars[1] = data->localData[0]->realVars[5] /* speed variable */;
  data->simulationInfo->outputVars[2] = data->localData[0]->realVars[6] /* x variable */;
  
  TRACE_POP
  return 0;
}

int LeadCar_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 8
type: SIMPLE_ASSIGN
accel = sine.offset + (if time < sine.startTime then 0.0 else sine.amplitude * sin(6.283185307179586 * sine.f * (time - sine.startTime) + sine.phase))
*/
void LeadCar_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  modelica_boolean tmp0;
  RELATIONHYSTERESIS(tmp0, data->localData[0]->timeValue, data->simulationInfo->realParameter[6] /* sine.startTime PARAM */, 0, Less);
  data->localData[0]->realVars[4] /* accel variable */ = data->simulationInfo->realParameter[4] /* sine.offset PARAM */ + (tmp0?0.0:(data->simulationInfo->realParameter[2] /* sine.amplitude PARAM */) * (sin(((6.283185307179586) * (data->simulationInfo->realParameter[3] /* sine.f PARAM */)) * (data->localData[0]->timeValue - data->simulationInfo->realParameter[6] /* sine.startTime PARAM */) + data->simulationInfo->realParameter[5] /* sine.phase PARAM */)));
  TRACE_POP
}
/*
equation index: 9
type: SIMPLE_ASSIGN
$DER.simple_car.speed = accel
*/
void LeadCar_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  data->localData[0]->realVars[2] /* der(simple_car.speed) STATE_DER */ = data->localData[0]->realVars[4] /* accel variable */;
  TRACE_POP
}
/*
equation index: 10
type: SIMPLE_ASSIGN
$DER.simple_car.x = simple_car.speed
*/
void LeadCar_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  data->localData[0]->realVars[3] /* der(simple_car.x) STATE_DER */ = data->localData[0]->realVars[0] /* simple_car.speed STATE(1,accel) */;
  TRACE_POP
}
/*
equation index: 11
type: SIMPLE_ASSIGN
speed = simple_car.speed
*/
void LeadCar_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  data->localData[0]->realVars[5] /* speed variable */ = data->localData[0]->realVars[0] /* simple_car.speed STATE(1,accel) */;
  TRACE_POP
}
/*
equation index: 12
type: SIMPLE_ASSIGN
x = simple_car.x
*/
void LeadCar_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  data->localData[0]->realVars[6] /* x variable */ = data->localData[0]->realVars[1] /* simple_car.x STATE(1,simple_car.speed) */;
  TRACE_POP
}

OMC_DISABLE_OPT
int LeadCar_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  LeadCar_functionLocalKnownVars(data, threadData);
  LeadCar_eqFunction_8(data, threadData);

  LeadCar_eqFunction_9(data, threadData);

  LeadCar_eqFunction_10(data, threadData);

  LeadCar_eqFunction_11(data, threadData);

  LeadCar_eqFunction_12(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int LeadCar_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void LeadCar_eqFunction_8(DATA* data, threadData_t *threadData);
extern void LeadCar_eqFunction_9(DATA* data, threadData_t *threadData);
extern void LeadCar_eqFunction_10(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
    LeadCar_eqFunction_8(data, threadData);

    LeadCar_eqFunction_9(data, threadData);

    LeadCar_eqFunction_10(data, threadData);
}

int LeadCar_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  LeadCar_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "LeadCar_12jac.h"
#include "LeadCar_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks LeadCar_callback = {
   NULL,    /* performSimulation */
   NULL,    /* performQSSSimulation */
   NULL,    /* updateContinuousSystem */
   LeadCar_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   LeadCar_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   LeadCar_initializeDAEmodeData,
   LeadCar_functionODE,
   LeadCar_functionAlgebraics,
   LeadCar_functionDAE,
   LeadCar_functionLocalKnownVars,
   LeadCar_input_function,
   LeadCar_input_function_init,
   LeadCar_input_function_updateStartValues,
   LeadCar_data_function,
   LeadCar_output_function,
   LeadCar_setc_function,
   LeadCar_function_storeDelayed,
   LeadCar_updateBoundVariableAttributes,
   LeadCar_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   LeadCar_functionRemovedInitialEquations,
   LeadCar_updateBoundParameters,
   LeadCar_checkForAsserts,
   LeadCar_function_ZeroCrossingsEquations,
   LeadCar_function_ZeroCrossings,
   LeadCar_function_updateRelations,
   LeadCar_zeroCrossingDescription,
   LeadCar_relationDescription,
   LeadCar_function_initSample,
   LeadCar_INDEX_JAC_A,
   LeadCar_INDEX_JAC_B,
   LeadCar_INDEX_JAC_C,
   LeadCar_INDEX_JAC_D,
   LeadCar_INDEX_JAC_F,
   LeadCar_initialAnalyticJacobianA,
   LeadCar_initialAnalyticJacobianB,
   LeadCar_initialAnalyticJacobianC,
   LeadCar_initialAnalyticJacobianD,
   LeadCar_initialAnalyticJacobianF,
   LeadCar_functionJacA_column,
   LeadCar_functionJacB_column,
   LeadCar_functionJacC_column,
   LeadCar_functionJacD_column,
   LeadCar_functionJacF_column,
   LeadCar_linear_model_frame,
   LeadCar_linear_model_datarecovery_frame,
   LeadCar_mayer,
   LeadCar_lagrange,
   LeadCar_pickUpBoundsForInputsInOptimization,
   LeadCar_setInputData,
   LeadCar_getTimeGrid,
   LeadCar_symbolicInlineSystem,
   LeadCar_function_initSynchronous,
   LeadCar_function_updateSynchronous,
   LeadCar_function_equationsSynchronous,
   LeadCar_inputNames,
   LeadCar_dataReconciliationInputNames,
   LeadCar_read_input_fmu,
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
void LeadCar_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &LeadCar_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "LeadCar";
  data->modelData->modelFilePrefix = "LeadCar";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/maurizio/OM";
  data->modelData->modelGUID = "{c85259b4-e755-4861-bfc5-ecaf2f25263a}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  data->modelData->runTestsuite = 0;
  
  data->modelData->nStates = 2;
  data->modelData->nVariablesReal = 7;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 7;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 3;
  
  data->modelData->nAliasReal = 5;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 1;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 1;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  
  GC_asprintf(&data->modelData->modelDataXml.fileName, "%s/LeadCar_info.json", data->modelData->resourcesDir);
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 13;
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

