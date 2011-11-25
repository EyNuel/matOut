#pragma once
#include <stdio.h>
#include "matOut.h"

void matClose(MATFile* file);

void matClose(MATFile* file){
	fclose(file);
}
