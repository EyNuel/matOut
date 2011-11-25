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
 * toolsMatlab.c                                                                        *
 * Collection of functions to write c arrays (pointers) to mxArrays.                    *
 *                                                                                      *
 ****************************************************************************************/

#pragma once
#include    "matOut.h"

#include    <stdint.h>
#include    <stdbool.h>


///Prototypes:
 
void    copyDoubleToPtr(double*, double*, uintptr_t);
void    copyDoubleToMxArray(double*, mxArray*, uintptr_t);
void    copyUInt32ToMxArray(uint32_t*, mxArray*, uintptr_t);
void    copyBoolToMxArray(bool*, mxArray*, uintptr_t);
        
void    copyDoubleToPtr2D(double**, double*, uintptr_t, uintptr_t);
void    copyDoubleToMxArray2D(double**, mxArray*, uintptr_t, uintptr_t);
void    copyDoubleToPtr2D_transposed(double**, mxArray*, uintptr_t, uintptr_t);
        
void    copyComplexToMxArray(complex double*, mxArray*, uintptr_t);
void    copyComplexToMxArray2D(complex double**, mxArray*, uintptr_t, uintptr_t);
void    copyComplexToMxArray2D_transposed(complex double**, mxArray*, uintptr_t, uintptr_t);



///Functions:

void    copyDoubleToPtr(double* origin, double* dest, uintptr_t nItems){
    //TODO replace all uses of this function with copyToMxArray()
    uintptr_t   i;
    
    for( i=0; i<nItems; i++ ){
        dest[i] = origin[i];
    }
}

void    copyDoubleToMxArray(double* origin, mxArray* dest, uintptr_t nItems){
    uintptr_t   i;
    double* destReal = NULL;
    
    destReal = mxGetData(dest);
    
    for( i=0; i<nItems; i++ ){
        destReal[i] = origin[i];
    }
}

void    copyUInt32ToMxArray(uint32_t* origin, mxArray* dest, uintptr_t nItems){
    uintptr_t   i;
    double* destReal = NULL;
    
    destReal = mxGetData(dest);
    
    for( i=0; i<nItems; i++ ){
        destReal[i] = (double)origin[i];
    }
}

void    copyBoolToMxArray(bool* origin, mxArray* dest, uintptr_t nItems){
    uintptr_t   i;
    double* destReal = NULL;
    
    destReal = mxGetData(dest);
    
    for( i=0; i<nItems; i++ ){
        destReal[i] = (double)origin[i];
    }
}

void    copyDoubleToPtr2D(double** origin, double* dest, uintptr_t rowSize, uintptr_t colSize){
    //TODO replace all uses of this function with copyToMxArray2D()
    uintptr_t   i,j;

    for( j=0; j<colSize; j++ ){
        for(i=0; i<rowSize; i++){
            dest[i*colSize +j] = origin[j][i];
        }
    }
}

void    copyDoubleToMxArray2D(double** origin, mxArray* dest, uintptr_t rowSize, uintptr_t colSize){
    uintptr_t   i,j;
    double* destReal = NULL;
    
    destReal = mxGetData(dest);

    for( j=0; j<colSize; j++ ){
        for(i=0; i<rowSize; i++){
            destReal[i*colSize +j] = origin[j][i];
        }
    }
}

void    copyDoubleToPtr2D_transposed(double** origin, mxArray* dest, uintptr_t dimZ, uintptr_t dimR){
    uintptr_t   i,j;
    double* destReal = NULL;
    
    destReal = mxGetData(dest);
    
    for( j=0; j<dimR; j++ ){
        for(i=0; i<dimZ; i++){
            destReal[j*dimZ + i] = origin[j][i];
        }
    }
}

void    copyComplexToMxArray(complex double* origin, mxArray* dest, uintptr_t nItems){
    uintptr_t   i;
    double* destImag = NULL;
    double* destReal = NULL;
    
    //get a pointer to the real and imaginary parts of the destination:
    destReal = mxGetData(dest);
    destImag = mxGetImagData(dest);
    
    for( i=0; i<nItems; i++ ){
        destReal[i] = creal(origin[i]);
        destImag[i] = cimag(origin[i]);
    }
}

void    copyComplexToMxArray2D(complex double** origin, mxArray* dest, uintptr_t dimZ, uintptr_t dimR){
    uintptr_t   i,j;
    double* destImag = NULL;
    double* destReal = NULL;
    
    //get a pointer to the real and imaginary parts of the destination:
    destReal = mxGetData(dest);
    destImag = mxGetImagData(dest);
    
    for( j=0; j<dimR; j++ ){
        for(i=0; i<dimZ; i++){
            destReal[j + i*dimR] = creal(origin[j][i]);
            destImag[j + i*dimR] = cimag(origin[j][i]);
        }
    }
}

void    copyComplexToMxArray2D_transposed(complex double** origin, mxArray* dest, uintptr_t dimZ, uintptr_t dimR){
    uintptr_t   i,j;
    double*     destImag = NULL;
    double*     destReal = NULL;
    
    //get a pointer to the real and imaginary parts of the destination:
    destReal = mxGetData(dest);
    destImag = mxGetImagData(dest);
    
    for( j=0; j<dimR; j++ ){
        for(i=0; i<dimZ; i++){
            destReal[j*dimZ + i] = creal(origin[j][i]);
            destImag[j*dimZ + i] = cimag(origin[j][i]);
        }
    }
}
