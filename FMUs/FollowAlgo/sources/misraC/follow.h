#ifndef _misraC_caccAlg_
#define _misraC_caccAlg_

#include <assert.h>
#include <stdio.h>
#include "misraC_basic_types.h"
/**
 * operating modes
 */
typedef enum { X1 } Mode;

/**
 * state attributes
 */
typedef struct { 
    Mode mode;
    Mode previous_mode;
    float32_t accel; //-- real
    float32_t accel_in; //-- real
    float32_t c1; //-- real
    float32_t ego_speed; //-- real
    float32_t ego_x; //-- real
    float32_t eps; //-- real
    float32_t lead_speed; //-- real
    float32_t lead_x; //-- real
    float32_t omega_n; //-- real
} State;

/**
 * init function
 */
void init(State* st);

/**
 * triggers
 */
bool per_tick(State* st);
State* tick(State* st);


/**
 * leave/enter functions
 */
void enter(Mode m, State* st);
void leave(Mode m, State* st);

#endif
