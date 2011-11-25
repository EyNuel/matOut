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
 
/****************************************************************************************
 * toolsMemory.c                                                                        *
 * Collection of utility functions for  handling memory.                                *
 * NOTE: All memory allocation functions in this file check for allocation errors.      *
 *                                                                                      *
 ****************************************************************************************/

#pragma     once
#include    <complex.h>
#include    <stdlib.h>
#include    <stdio.h>
#include    <string.h>
#include    <stdint.h>
#include    <stdbool.h>
#include    "toolsMisc.c"


///Function Prototypes:
char*           mallocChar(uintptr_t);
bool*           mallocBool(uintptr_t numBools);
bool*           reallocBool(bool* old, uintptr_t numBools);
uint32_t*       mallocUint(uintptr_t);
uint32_t*       reallocUint(uint32_t*, uintptr_t);
int32_t*        mallocInt(uintptr_t);
int32_t*        reallocInt(int32_t*, uintptr_t);
double*         mallocDouble(uintptr_t);
double*         reallocDouble(double*, uintptr_t);
void            freeDouble(double*);
double**        mallocDouble2D(uintptr_t, uintptr_t);
void            freeDouble2D(double**, uintptr_t);
complex double* mallocComplex(uintptr_t);
complex double* reallocComplex(complex double*, uintptr_t);
void            freeComplex(complex double*);
complex double** mallocComplex2D(uintptr_t, uintptr_t);
void            freeComplex2D(complex double**, uintptr_t);

///Functions:


char*               mallocChar(uintptr_t numChars){
    /*
        Allocates a char string and returns a pointer to it in case of success,
        exits with error code otherwise.
    */
    
    char*   temp = NULL;    //temporary pointer
    temp = malloc((size_t)numChars*sizeof(char));
    if (temp == NULL){
        fatal("Memory allocation error.\n");
    }
    return temp;
}


bool*           mallocBool(uintptr_t numBools){
    /*
        Allocates a char string and returns a pointer to it in case of success,
        exits with error code otherwise.
    */
    bool*   temp = NULL;    //temporary pointer

    temp = malloc(numBools*sizeof(bool));
    return temp;
}

bool*           reallocBool(bool* old, uintptr_t numBools){
    /*
        Allocates an uint array and returns a pointer to it in case of success,
        exits with error code otherwise.
    */
    DEBUG(10,"reallocBool(),\t in\n");
    bool*   new = NULL;

    if(numBools == 0){
        free(old);
    }else{
        new = realloc(old, numBools*sizeof(bool));
        if (new == NULL){
            fatal("Memory allocation error.\n");
        }
    }
    DEBUG(10,"reallocBool(),\t out\n");
    return new;
}

uint32_t*           mallocUint(uintptr_t numUints){
    /*
        Allocates a char string and returns a pointer to it in case of success,
        exits with error code otherwise.
    */
    uint32_t*   temp = NULL;    //temporary pointer

    temp = malloc(numUints*sizeof(uint32_t));
    return temp;
}

uint32_t*           reallocUint(uint32_t* old, uintptr_t numUints){
    /*
        Allocates an uint array and returns a pointer to it in case of success,
        exits with error code otherwise.
    */
    DEBUG(10,"reallocUint(),\t in\n");
    uint32_t*   new = NULL;

    if(numUints == 0){
        free(old);
    }else{
        new = realloc(old, numUints*sizeof(uint32_t));
        if (new == NULL){
            fatal("Memory allocation error.\n");
        }
    }
    DEBUG(10,"reallocUint(),\t out\n");
    return new;
}

int32_t*            mallocInt(uintptr_t numInts){
    /*
        Allocates a char string and returns a pointer to it in case of success,
        exits with error code otherwise.
    */
    int32_t*    temp = NULL;    //temporary pointer

    temp = malloc(numInts*sizeof(int32_t));
    return temp;
}

int32_t*            reallocInt(int32_t* old, uintptr_t numInts){
    /*
        Allocates a char string and returns a pointer to it in case of success,
        exits with error code otherwise.
    */
    int32_t*    new = NULL;
    
    if(numInts == 0){
        free(old);
    }else{
        new = realloc(old, numInts*sizeof(int32_t));
        if (new == NULL){
            fatal("Memory allocation error.\n");
        }
    }
    return new;
}

double*             mallocDouble(uintptr_t numDoubles){
    /*
        Allocates an array of doubles and returns a pointer to it in case of success,
        Exits with error code otherwise.
    */
    DEBUG(9,"mallocDouble(),\tin\n");
    double* temp = NULL;    //temporary pointer
    temp = malloc(numDoubles * sizeof(double));
    if(temp == NULL){
        fatal("Memory alocation error.\n");
    }
    DEBUG(9,"mallocDouble(),\tout\n");
    return temp;
}
    
double*             reallocDouble(double* old, uintptr_t numDoubles){
    DEBUG(10,"reallocDouble(),\tin\n");
    double*     new = NULL;
    
    if(numDoubles == 0){
        free(old);
    }else{
        new = realloc(old, numDoubles*sizeof(double));
        if (new == NULL){
            fatal("Memory allocation error.\n");
        }
    }
    DEBUG(10,"reallocDouble(),\tout\n");
    return new;
}
    
void                freeDouble(double* greenMile){
    if(greenMile != NULL){
        free(greenMile);
    }
}
    
double**            mallocDouble2D(uintptr_t numRows, uintptr_t numCols){
    /*
     * Returns a pointer to an array of pointer do doubles.
     * Or:
     * Return a 2D Array.
     */

    uint32_t    i;
    double**    array = NULL;
    array = malloc(numRows * sizeof(uintptr_t*));   //malloc an array of pointers
    
    if(array == NULL)
        fatal("Memory allocation error.\n");

    for(i = 0; i < numRows; i++){
        array[i] = mallocDouble(numCols);   //Nota that mallocDouble() already checks for allocation errors
    }

    return array;
}

void                freeDouble2D(double** greenMile, uintptr_t items){
    /*
     * frees the memory allocated to a double pointer of type double.
     */
     uintptr_t  i;
     
    for(i=0; i<items; i++){
        if(greenMile[i] != NULL){
            free(greenMile[i]);
        }
    }
    free(greenMile);
}

complex double*     mallocComplex(uintptr_t numComplex){
    complex double* temp = NULL;
    uintptr_t       i;
    
    temp = malloc(numComplex * sizeof(complex double));
    if(temp == NULL)
        fatal("Memory alocation error.");
    //Initialize to zero:
    for (i=0; i<numComplex; i++){
        temp[i] = 0 + 0*I;
    }
    
    return temp;
}

complex double*     reallocComplex(complex double* old, uintptr_t numComplex){
    complex double* new = NULL;

    if(numComplex == 0){
        free(old);
    }else{
        new = realloc(old, numComplex*sizeof(complex double));
        if (new == NULL){
            fatal("Memory allocation error.\n");
        }
    }
    return new;
}

void                freeComplex(complex double* greenMile){
    if(greenMile != NULL){
        free(greenMile);
    }
}

complex double**    mallocComplex2D(uintptr_t numRows, uintptr_t numCols){
    /*
     * Returns a pointer to an array of pointer do doubles.
     * Or:
     * Return a 2D Array.
     */

    uint32_t    i;
    complex double**    array = NULL;
    array = malloc(numRows * sizeof(uintptr_t*));   //malloc an array of pointers
    
    if(array == NULL)
        fatal("Memory allocation error.\n");

    for(i = 0; i < numRows; i++){
        array[i] = mallocComplex(numCols);  //Nota that mallocDouble() already checks for allocation errors
    }

    return array;
}

void                freeComplex2D(complex double** greenMile, uintptr_t items){
    /*
     * frees the memory allocated to a double pointer of type complex double.
     */
     uintptr_t  i;
     
    for(i=0; i<items; i++){
        if(greenMile[i] != NULL){
            free(greenMile[i]);
        }
    }
    free(greenMile);
}




