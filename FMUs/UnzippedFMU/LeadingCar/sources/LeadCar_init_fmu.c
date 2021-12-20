#include "simulation_data.h"

OMC_DISABLE_OPT
void LeadCar_read_input_fmu(MODEL_DATA* modelData, SIMULATION_INFO* simulationInfo)
{
  simulationInfo->startTime = 0.0;
  simulationInfo->stopTime = 1.0;
  simulationInfo->stepSize = 0.002;
  simulationInfo->tolerance = 1e-06;
  simulationInfo->solverMethod = "dassl";
  simulationInfo->outputFormat = "mat";
  simulationInfo->variableFilter = ".*";
  simulationInfo->OPENMODELICAHOME = "/usr/bin/..";
  modelData->realVarsData[0].info.id = 1000;
  modelData->realVarsData[0].info.name = "simple_car.speed";
  modelData->realVarsData[0].info.comment = "";
  modelData->realVarsData[0].info.info.filename = "/home/maurizio/OM/Simple_car.mo";
  modelData->realVarsData[0].info.info.lineStart = 5;
  modelData->realVarsData[0].info.info.colStart = 3;
  modelData->realVarsData[0].info.info.lineEnd = 6;
  modelData->realVarsData[0].info.info.colEnd = 202;
  modelData->realVarsData[0].info.info.readonly = 0;
  modelData->realVarsData[0].attribute.unit = "";
  modelData->realVarsData[0].attribute.displayUnit = "";
  modelData->realVarsData[0].attribute.min = -DBL_MAX;
  modelData->realVarsData[0].attribute.max = DBL_MAX;
  modelData->realVarsData[0].attribute.fixed = 0;
  modelData->realVarsData[0].attribute.useNominal = 0;
  modelData->realVarsData[0].attribute.nominal = 1.0;
  modelData->realVarsData[0].attribute.start = 0.0;
  modelData->realVarsData[1].info.id = 1001;
  modelData->realVarsData[1].info.name = "simple_car.x";
  modelData->realVarsData[1].info.comment = "";
  modelData->realVarsData[1].info.info.filename = "/home/maurizio/OM/Simple_car.mo";
  modelData->realVarsData[1].info.info.lineStart = 3;
  modelData->realVarsData[1].info.info.colStart = 3;
  modelData->realVarsData[1].info.info.lineEnd = 4;
  modelData->realVarsData[1].info.info.colEnd = 201;
  modelData->realVarsData[1].info.info.readonly = 0;
  modelData->realVarsData[1].attribute.unit = "";
  modelData->realVarsData[1].attribute.displayUnit = "";
  modelData->realVarsData[1].attribute.min = -DBL_MAX;
  modelData->realVarsData[1].attribute.max = DBL_MAX;
  modelData->realVarsData[1].attribute.fixed = 0;
  modelData->realVarsData[1].attribute.useNominal = 0;
  modelData->realVarsData[1].attribute.nominal = 1.0;
  modelData->realVarsData[1].attribute.start = 0.0;
  modelData->realVarsData[2].info.id = 1002;
  modelData->realVarsData[2].info.name = "der(simple_car.speed)";
  modelData->realVarsData[2].info.comment = "";
  modelData->realVarsData[2].info.info.filename = "/home/maurizio/OM/Simple_car.mo";
  modelData->realVarsData[2].info.info.lineStart = 5;
  modelData->realVarsData[2].info.info.colStart = 3;
  modelData->realVarsData[2].info.info.lineEnd = 6;
  modelData->realVarsData[2].info.info.colEnd = 202;
  modelData->realVarsData[2].info.info.readonly = 0;
  modelData->realVarsData[2].attribute.unit = "";
  modelData->realVarsData[2].attribute.displayUnit = "";
  modelData->realVarsData[2].attribute.min = -DBL_MAX;
  modelData->realVarsData[2].attribute.max = DBL_MAX;
  modelData->realVarsData[2].attribute.fixed = 0;
  modelData->realVarsData[2].attribute.useNominal = 0;
  modelData->realVarsData[2].attribute.nominal = 1.0;
  modelData->realVarsData[2].attribute.start = 0.0;
  modelData->realVarsData[3].info.id = 1003;
  modelData->realVarsData[3].info.name = "der(simple_car.x)";
  modelData->realVarsData[3].info.comment = "";
  modelData->realVarsData[3].info.info.filename = "/home/maurizio/OM/Simple_car.mo";
  modelData->realVarsData[3].info.info.lineStart = 3;
  modelData->realVarsData[3].info.info.colStart = 3;
  modelData->realVarsData[3].info.info.lineEnd = 4;
  modelData->realVarsData[3].info.info.colEnd = 201;
  modelData->realVarsData[3].info.info.readonly = 0;
  modelData->realVarsData[3].attribute.unit = "";
  modelData->realVarsData[3].attribute.displayUnit = "";
  modelData->realVarsData[3].attribute.min = -DBL_MAX;
  modelData->realVarsData[3].attribute.max = DBL_MAX;
  modelData->realVarsData[3].attribute.fixed = 0;
  modelData->realVarsData[3].attribute.useNominal = 0;
  modelData->realVarsData[3].attribute.nominal = 1.0;
  modelData->realVarsData[3].attribute.start = 0.0;
  modelData->realVarsData[4].info.id = 1004;
  modelData->realVarsData[4].info.name = "accel";
  modelData->realVarsData[4].info.comment = "";
  modelData->realVarsData[4].info.info.filename = "/home/maurizio/OM/car_sim.mo";
  modelData->realVarsData[4].info.info.lineStart = 0;
  modelData->realVarsData[4].info.info.colStart = 0;
  modelData->realVarsData[4].info.info.lineEnd = 0;
  modelData->realVarsData[4].info.info.colEnd = 0;
  modelData->realVarsData[4].info.info.readonly = 0;
  modelData->realVarsData[4].attribute.unit = "";
  modelData->realVarsData[4].attribute.displayUnit = "";
  modelData->realVarsData[4].attribute.min = -DBL_MAX;
  modelData->realVarsData[4].attribute.max = DBL_MAX;
  modelData->realVarsData[4].attribute.fixed = 0;
  modelData->realVarsData[4].attribute.useNominal = 0;
  modelData->realVarsData[4].attribute.nominal = 1.0;
  modelData->realVarsData[4].attribute.start = 0.0;
  modelData->realVarsData[5].info.id = 1005;
  modelData->realVarsData[5].info.name = "speed";
  modelData->realVarsData[5].info.comment = "";
  modelData->realVarsData[5].info.info.filename = "/home/maurizio/OM/car_sim.mo";
  modelData->realVarsData[5].info.info.lineStart = 0;
  modelData->realVarsData[5].info.info.colStart = 0;
  modelData->realVarsData[5].info.info.lineEnd = 0;
  modelData->realVarsData[5].info.info.colEnd = 0;
  modelData->realVarsData[5].info.info.readonly = 0;
  modelData->realVarsData[5].attribute.unit = "";
  modelData->realVarsData[5].attribute.displayUnit = "";
  modelData->realVarsData[5].attribute.min = -DBL_MAX;
  modelData->realVarsData[5].attribute.max = DBL_MAX;
  modelData->realVarsData[5].attribute.fixed = 0;
  modelData->realVarsData[5].attribute.useNominal = 0;
  modelData->realVarsData[5].attribute.nominal = 1.0;
  modelData->realVarsData[5].attribute.start = 0.0;
  modelData->realVarsData[6].info.id = 1006;
  modelData->realVarsData[6].info.name = "x";
  modelData->realVarsData[6].info.comment = "";
  modelData->realVarsData[6].info.info.filename = "/home/maurizio/OM/car_sim.mo";
  modelData->realVarsData[6].info.info.lineStart = 0;
  modelData->realVarsData[6].info.info.colStart = 0;
  modelData->realVarsData[6].info.info.lineEnd = 0;
  modelData->realVarsData[6].info.info.colEnd = 0;
  modelData->realVarsData[6].info.info.readonly = 0;
  modelData->realVarsData[6].attribute.unit = "";
  modelData->realVarsData[6].attribute.displayUnit = "";
  modelData->realVarsData[6].attribute.min = -DBL_MAX;
  modelData->realVarsData[6].attribute.max = DBL_MAX;
  modelData->realVarsData[6].attribute.fixed = 0;
  modelData->realVarsData[6].attribute.useNominal = 0;
  modelData->realVarsData[6].attribute.nominal = 1.0;
  modelData->realVarsData[6].attribute.start = 0.0;
  modelData->realParameterData[0].info.id = 1007;
  modelData->realParameterData[0].info.name = "simple_car.v0";
  modelData->realParameterData[0].info.comment = "";
  modelData->realParameterData[0].info.info.filename = "/home/maurizio/OM/Simple_car.mo";
  modelData->realParameterData[0].info.info.lineStart = 11;
  modelData->realParameterData[0].info.info.colStart = 3;
  modelData->realParameterData[0].info.info.lineEnd = 11;
  modelData->realParameterData[0].info.info.colEnd = 27;
  modelData->realParameterData[0].info.info.readonly = 0;
  modelData->realParameterData[0].attribute.unit = "";
  modelData->realParameterData[0].attribute.displayUnit = "";
  modelData->realParameterData[0].attribute.min = -DBL_MAX;
  modelData->realParameterData[0].attribute.max = DBL_MAX;
  modelData->realParameterData[0].attribute.fixed = 1;
  modelData->realParameterData[0].attribute.useNominal = 0;
  modelData->realParameterData[0].attribute.nominal = 1.0;
  modelData->realParameterData[0].attribute.start = -0.1;
  modelData->realParameterData[1].info.id = 1008;
  modelData->realParameterData[1].info.name = "simple_car.x0";
  modelData->realParameterData[1].info.comment = "";
  modelData->realParameterData[1].info.info.filename = "/home/maurizio/OM/Simple_car.mo";
  modelData->realParameterData[1].info.info.lineStart = 10;
  modelData->realParameterData[1].info.info.colStart = 3;
  modelData->realParameterData[1].info.info.lineEnd = 10;
  modelData->realParameterData[1].info.info.colEnd = 24;
  modelData->realParameterData[1].info.info.readonly = 0;
  modelData->realParameterData[1].attribute.unit = "";
  modelData->realParameterData[1].attribute.displayUnit = "";
  modelData->realParameterData[1].attribute.min = -DBL_MAX;
  modelData->realParameterData[1].attribute.max = DBL_MAX;
  modelData->realParameterData[1].attribute.fixed = 1;
  modelData->realParameterData[1].attribute.useNominal = 0;
  modelData->realParameterData[1].attribute.nominal = 1.0;
  modelData->realParameterData[1].attribute.start = 3.0;
  modelData->realParameterData[2].info.id = 1009;
  modelData->realParameterData[2].info.name = "sine.amplitude";
  modelData->realParameterData[2].info.comment = "Amplitude of sine wave";
  modelData->realParameterData[2].info.info.filename = "/home/maurizio/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo";
  modelData->realParameterData[2].info.info.lineStart = 293;
  modelData->realParameterData[2].info.info.colStart = 5;
  modelData->realParameterData[2].info.info.lineEnd = 294;
  modelData->realParameterData[2].info.info.colEnd = 98;
  modelData->realParameterData[2].info.info.readonly = 0;
  modelData->realParameterData[2].attribute.unit = "";
  modelData->realParameterData[2].attribute.displayUnit = "";
  modelData->realParameterData[2].attribute.min = -DBL_MAX;
  modelData->realParameterData[2].attribute.max = DBL_MAX;
  modelData->realParameterData[2].attribute.fixed = 1;
  modelData->realParameterData[2].attribute.useNominal = 0;
  modelData->realParameterData[2].attribute.nominal = 1.0;
  modelData->realParameterData[2].attribute.start = 1.2;
  modelData->realParameterData[3].info.id = 1010;
  modelData->realParameterData[3].info.name = "sine.f";
  modelData->realParameterData[3].info.comment = "Frequency of sine wave";
  modelData->realParameterData[3].info.info.filename = "/home/maurizio/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo";
  modelData->realParameterData[3].info.info.lineStart = 295;
  modelData->realParameterData[3].info.info.colStart = 5;
  modelData->realParameterData[3].info.info.lineEnd = 295;
  modelData->realParameterData[3].info.info.colEnd = 63;
  modelData->realParameterData[3].info.info.readonly = 0;
  modelData->realParameterData[3].attribute.unit = "Hz";
  modelData->realParameterData[3].attribute.displayUnit = "";
  modelData->realParameterData[3].attribute.min = -DBL_MAX;
  modelData->realParameterData[3].attribute.max = DBL_MAX;
  modelData->realParameterData[3].attribute.fixed = 1;
  modelData->realParameterData[3].attribute.useNominal = 0;
  modelData->realParameterData[3].attribute.nominal = 1.0;
  modelData->realParameterData[3].attribute.start = 0.05;
  modelData->realParameterData[4].info.id = 1011;
  modelData->realParameterData[4].info.name = "sine.offset";
  modelData->realParameterData[4].info.comment = "Offset of output signal y";
  modelData->realParameterData[4].info.info.filename = "/home/maurizio/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo";
  modelData->realParameterData[4].info.info.lineStart = 479;
  modelData->realParameterData[4].info.info.colStart = 5;
  modelData->realParameterData[4].info.info.lineEnd = 479;
  modelData->realParameterData[4].info.info.colEnd = 56;
  modelData->realParameterData[4].info.info.readonly = 0;
  modelData->realParameterData[4].attribute.unit = "";
  modelData->realParameterData[4].attribute.displayUnit = "";
  modelData->realParameterData[4].attribute.min = -DBL_MAX;
  modelData->realParameterData[4].attribute.max = DBL_MAX;
  modelData->realParameterData[4].attribute.fixed = 1;
  modelData->realParameterData[4].attribute.useNominal = 0;
  modelData->realParameterData[4].attribute.nominal = 1.0;
  modelData->realParameterData[4].attribute.start = -0.01;
  modelData->realParameterData[5].info.id = 1012;
  modelData->realParameterData[5].info.name = "sine.phase";
  modelData->realParameterData[5].info.comment = "Phase of sine wave";
  modelData->realParameterData[5].info.info.filename = "/home/maurizio/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo";
  modelData->realParameterData[5].info.info.lineStart = 296;
  modelData->realParameterData[5].info.info.colStart = 5;
  modelData->realParameterData[5].info.info.lineEnd = 296;
  modelData->realParameterData[5].info.info.colEnd = 52;
  modelData->realParameterData[5].info.info.readonly = 0;
  modelData->realParameterData[5].attribute.unit = "rad";
  modelData->realParameterData[5].attribute.displayUnit = "deg";
  modelData->realParameterData[5].attribute.min = -DBL_MAX;
  modelData->realParameterData[5].attribute.max = DBL_MAX;
  modelData->realParameterData[5].attribute.fixed = 1;
  modelData->realParameterData[5].attribute.useNominal = 0;
  modelData->realParameterData[5].attribute.nominal = 1.0;
  modelData->realParameterData[5].attribute.start = 0.0;
  modelData->realParameterData[6].info.id = 1013;
  modelData->realParameterData[6].info.name = "sine.startTime";
  modelData->realParameterData[6].info.comment = "Output y = offset for time < startTime";
  modelData->realParameterData[6].info.info.filename = "/home/maurizio/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo";
  modelData->realParameterData[6].info.info.lineStart = 480;
  modelData->realParameterData[6].info.info.colStart = 5;
  modelData->realParameterData[6].info.info.lineEnd = 480;
  modelData->realParameterData[6].info.info.colEnd = 75;
  modelData->realParameterData[6].info.info.readonly = 0;
  modelData->realParameterData[6].attribute.unit = "s";
  modelData->realParameterData[6].attribute.displayUnit = "";
  modelData->realParameterData[6].attribute.min = -DBL_MAX;
  modelData->realParameterData[6].attribute.max = DBL_MAX;
  modelData->realParameterData[6].attribute.fixed = 1;
  modelData->realParameterData[6].attribute.useNominal = 0;
  modelData->realParameterData[6].attribute.nominal = 1.0;
  modelData->realParameterData[6].attribute.start = 0.0;
}