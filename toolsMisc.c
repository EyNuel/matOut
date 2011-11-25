/*
 *  Copyright 2011 Emanuel Ey <emanuel.ey@gmail.com>
 * 
 *  This file is part of matOut.
 *
 *  MatOut is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  MatOut is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with matOut.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include <stdio.h>

//function macro used for showing debugging information:
#if VERBOSE == 1
    #define WHERESTR                "[%s,\tline %d]:\t"
    #define WHEREARG                __FILE__, __LINE__
    #define DEBUG(level, ...)       if(VERBOSITY >= level){fprintf(stderr, WHERESTR, WHEREARG);fprintf(stderr, __VA_ARGS__);}
#else
    //this should be optimized away nicely by the compiler:
    #define DEBUG(level, ...)       {}
#endif


void        fatal(const char* message);
double      min(double a, double b);
double      max(double a, double b);


void        fatal(const char* message){
    /*
        Prints a message and terminates the program with an error.
        Closes all open i/o streams before exiting.
    */
    printf("%s\n", message);
    fflush(NULL);               //flushes all i/o streams.
    exit(EXIT_FAILURE);
}


double      min(double a, double b){
    if( a <= b){
        return a;
    }else{
        return b;
    }
}

double      max(double a, double b){
    if( a > b){
        return a;
    }else{
        return b;
    }
}
