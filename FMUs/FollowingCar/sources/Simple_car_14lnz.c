/* Linearization */
#include "Simple_car_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *Simple_car_linear_model_frame()
{
  return "model linearized_model \"Simple_car\" \n  parameter Integer n = 2 \"number of states\";\n  parameter Integer m = 1 \"number of inputs\";\n  parameter Integer p = 2 \"number of outputs\";\n"
  "  parameter Real x0[n] = %s;\n"
  "  parameter Real u0[m] = %s;\n"
  "\n"
  "  parameter Real A[n, n] =\n\t[%s];\n\n"
  "  parameter Real B[n, m] =\n\t[%s];\n\n"
  "  parameter Real C[p, n] =\n\t[%s];\n\n"
  "  parameter Real D[p, m] =\n\t[%s];\n\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[m](start=u0);\n"
  "  output Real y[p];\n"
  "\n"
  "  Real 'x_$outputAlias_speed' = x[1];\n""  Real 'x_$outputAlias_x' = x[2];\n"
  "  Real 'u_accel' = u[1];\n"
  "  Real 'y_speed' = y[1];\n""  Real 'y_x' = y[2];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linearized_model;\n";
}
const char *Simple_car_linear_model_datarecovery_frame()
{
  return "model linearized_model \"Simple_car\" \n parameter Integer n = 2 \"number of states\";\n  parameter Integer m = 1 \"number of inputs\";\n  parameter Integer p = 2 \"number of outputs\";\n  parameter Integer nz = 3 \"data recovery variables\";\n"
  "  parameter Real x0[2] = %s;\n"
  "  parameter Real u0[1] = %s;\n"
  "  parameter Real z0[3] = %s;\n"
  "\n"
  "  parameter Real A[n, n] =\n\t[%s];\n\n"
  "  parameter Real B[n, m] =\n\t[%s];\n\n"
  "  parameter Real C[p, n] =\n\t[%s];\n\n"
  "  parameter Real D[p, m] =\n\t[%s];\n\n"
  "  parameter Real Cz[nz, n] =\n\t[%s];\n\n"
  "  parameter Real Dz[nz, m] =\n\t[%s];\n\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[m](start=u0);\n"
  "  output Real y[p];\n"
  "  output Real z[nz];\n"
  "\n"
  "  Real 'x_$outputAlias_speed' = x[1];\n""  Real 'x_$outputAlias_x' = x[2];\n"
  "  Real 'u_accel' = u[1];\n"
  "  Real 'y_speed' = y[1];\n""  Real 'y_x' = y[2];\n"
  "  Real 'z_accel' = z[1];\n""  Real 'z_speed' = z[2];\n""  Real 'z_x' = z[3];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linearized_model;\n";
}
#if defined(__cplusplus)
}
#endif

