/*! \file skeleton.c 
 * In this file there are the implementations
 * of the fuctions declared in fmu.h
 * along with the data needed.
 */
#include "fmu.h"
#include "misraC/follow.h"


State st; /*!< structure containing the state of the model */
int first = 0; /* variable for execution of setup option during first step only */


 /**
       * function for the initialization of the model.
       * It calls the init function of the model and
       * 	sets the output
       * @param location is the directory where the fmu has been unzipped. Might be used in future version
       * 
       */


void initialize() {
    init(&st);
    fmiBuffer.realBuffer[1] = st.accel;
    
    
}

/**
 * function that performs a step of the simulation model.
 * At first the inputs of the are updated with the values fom the master algorithm
 * Then the tick function is called
 * Finally the outputs of the model are forwarded to the master algorithm 
 * @param action is the action to perform. Might be used in future version
 */
void doStep() { 
if(first == 0){

    st.c1 = fmiBuffer.realBuffer[3] ;
    st.eps = fmiBuffer.realBuffer[6] ;
    st.omega_n = fmiBuffer.realBuffer[9] ;
    
    first = 1;
}
	
    st.accel_in = fmiBuffer.realBuffer[2];
    st.ego_speed = fmiBuffer.realBuffer[4];
    st.ego_x = fmiBuffer.realBuffer[5];
    st.lead_speed = fmiBuffer.realBuffer[7];
    st.lead_x = fmiBuffer.realBuffer[8];
	
    tick(&st);
    
    
    fmiBuffer.realBuffer[1] = st.accel;
    /*
    fmiBuffer.realBuffer[3] = st.c1;
    fmiBuffer.realBuffer[6] = st.eps;
    fmiBuffer.realBuffer[9] = st.omega_n;*/
}

void terminate(){ }


