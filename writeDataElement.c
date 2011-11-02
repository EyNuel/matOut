#pragma once
#include <stdio.h>
#include <stdint.h>
#include "matlabOut.h"

void writeDataElement(FILE* outfile, uint32_t dataType, void* data, size_t dataItemSize, uint32_t nDataItems);

void writeDataElement(FILE* outfile, uint32_t dataType, void* data, size_t dataItemSize, uint32_t nDataItems){
	/*
	 * TODO: documentation
	 * TODO: verify successfull write
	 */
	uint8_t		tempUInt8;
	uint32_t	nBytes;
	uint32_t	paddingBytes = 0;
	uintptr_t	i;
	char		emptyChar = 0;
	
	//write the datatype identifier
	fwrite(&dataType, sizeof(uint32_t), 1, outfile);
	
	//write the number of data bytes to the data element's tag:
	nBytes	= dataItemSize * nDataItems;
	if (dataType == mxCHAR_CLASS){
		//mxCHAR_CLASS is strange: altough the data is 8bit, it is written as 16bit uints,
		//making this just abit trickier
		nBytes *= 2;
	}
	
	fwrite(&nBytes, sizeof(uint32_t), 1, outfile);
	
	
	// write the data
	if (dataType == mxCHAR_CLASS){
		//Again, because mxCharClass is strange, we have to write one char
		//at a time, each followed by a null byte
		tempUInt8 = 0x00;
		for (uintptr_t iChar=0; iChar<strlen(data); iChar++){
			fwrite(&data[iChar], sizeof(uint8_t), 1, outfile);
			fwrite(&tempUInt8, sizeof(uint8_t), 1, outfile);
		}
		
	}else{
		fwrite(data, dataItemSize, nDataItems, outfile);
	}
	
	/*
	 * padding may be required to ensure 64b boundaries between
	 * data elements.
	 */
	if (nBytes % 8 > 0){
		paddingBytes= 8 - nBytes % 8;	//This could probably be neatly rewritten with the ternary operator
	}
	printf("numBytes: %u, paddingBytes: %u\n", nBytes, paddingBytes);
	for (i=0; i<paddingBytes; i++){
		fwrite(&emptyChar, sizeof(uint8_t), 1, outfile);
	}
}