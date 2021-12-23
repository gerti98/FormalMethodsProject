#include "Attack_fmu.h"
/**
 * init function
 */
void init(State* st) { 
    st->previous_mode = X1;
    st->mode = X1;
    st->attack_time = 0.0f;
    st->attack_value = 0.0f;
    st->input = 0.0f;
    st->output = 0.0f;
    st->step_size = 0.0f;
    st->time = 0.0f;
    st->attack_duration = 0.0f;
    st->attack_occurrences = 0.0f;
    st->attack_distance = 0.0f;
}

/**
 * leave/enter functions
 */
void enter(Mode m, State* st) { 
    st->mode = m;
}
void leave(Mode m, State* st) { 
    st->previous_mode = m;
}

/**
 * triggers
 */
bool per_tick(State* st) {
    return (st->mode == X1 && ( st->time < st->attack_time ))
            || (st->mode == X1 && ( st->time >= st->attack_time ));
}

bool under_attack(State* st){
    float64_t attack_time_i;
    if(st->time >= st->attack_time) {
        for (unsigned int i = 0; i < st->attack_occurrences; ++i){
            //individuo l'inizio di ogni intervallo di attacco
            attack_time_i = st->attack_time + (st->attack_duration + st->attack_distance)*i;
            //vedo se sono nel mezzo di un intervallo
            if(st->time >= attack_time_i && st->time <= attack_time_i + st->attack_duration)
                return true;
        }
    }
    return false;
}

State* tick(State* st) {
    // assert( per_tick(st) );
    if (st->mode == X1 && !under_attack(st)) {
        #ifdef DBG
        _dbg_print_condition("st->mode == X1 && ( st->time < st->attack_time )");
        #endif
        leave(X1, st);
        st->output = st->input;
        st->time = st->time + st->step_size;
        enter(X1, st);
    } else if (st->mode == X1 && under_attack(st)) {
        #ifdef DBG
        _dbg_print_condition("st->mode == X1 && ( st->time >= st->attack_time )");
        #endif
        leave(X1, st);
        st->output = st->attack_value;
        st->time = st->time + st->step_size;
        enter(X1, st);
    }
    #ifdef DBG
    _dbg_print_state(st);
    #endif
    return st;
}




