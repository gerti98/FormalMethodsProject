#include "follow.h"
#include <stdio.h>
#include <math.h>
#include <time.h>

/**
 * init function
 */
void init(State* st) { 
    st->previous_mode = X1;
    st->mode = X1;
    st->accel = 0.0f;
    st->accel_in = 0.0f;
    st->c1 = 0.2f;
    st->ego_speed = 0.0f;
    st->ego_x = 0.0f;
    st->eps = 0.5f;
    st->lead_speed = 0.0f;
    st->lead_x = 0.0f;
    st->omega_n = 0.0f;
}

/**
 * leave/enter functionsmode
 */
void enter(Mode m, State* st) { 
    st->mode = m;
}
void leave(Mode m, State* st) { 
    st->previous_mode = m;
}

float follow(float C1, float dampingRatio, float controllerBandwidth, float l_prec, float targetDistance,  
			float x_i, float x_prec, float x_0, float der1_x_i, float der1_x_prec, float der1_x_0, float der2_x_prec, float der2_x_0 )
{
	float desiredAcceleration=0;
	float alfa1=0 , alfa2=0, alfa3=0, alfa4=0, alfa5=0, calcOptimization3=0;
	float epsilon_i = 0, der1_epsilon_i = 0;
	
	
	alfa1 = 1 - C1;
	alfa2 = C1;
	
	calcOptimization3 = C1* ( dampingRatio+ sqrt( dampingRatio*dampingRatio - 1 ));
	alfa3 = - ( 2*dampingRatio - calcOptimization3 ) * controllerBandwidth;
	alfa4 = - (calcOptimization3 * controllerBandwidth);
	alfa5 = - (controllerBandwidth*controllerBandwidth);
	
	epsilon_i = x_i - x_prec + l_prec + targetDistance;
	der1_epsilon_i = der1_x_i - der1_x_prec;
	
	desiredAcceleration = (alfa1 * der2_x_prec) + (alfa1* der2_x_0) + (alfa3 * der1_epsilon_i) + (alfa4 * (der1_x_i - der1_x_0)) + (alfa5 * epsilon_i);
	return desiredAcceleration;
}


/**
 * triggers
 */
bool per_tick(State* st) {
    return (st->mode == X1 && ( TRUE ));
}
State* tick(State* st) {
    // assert( per_tick(st) );
    if (st->mode == X1 && ( TRUE )) {
        #ifdef DBG
        _dbg_print_condition("st->mode == X1 && ( TRUE )");
        #endif
        leave(X1, st);
        st->accel = follow(st->c1, st->eps, st->omega_n, 5, 10, st->ego_x, st->lead_x,st->lead_x,st->ego_speed,st->lead_speed,st->lead_speed,st->accel_in,st->accel_in);
        enter(X1, st);
    }
    #ifdef DBG
    _dbg_print_state(st);
    #endif
    return st;
}




