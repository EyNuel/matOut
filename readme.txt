## Introduction
  As the name suggest, _matOut_ consists a set of functions created to
  write Matlab's .mat files.  
  Basically I had some code which relied heavily on Matlab's API for file
  output, and I needed to eliminate this code's dependency on Matlab
  without having to re-engineer large parts of my code.  
  There is at least one open-source library for writing Matlab files:
  [matio](http://sourceforge.net/projects/matio/).
  Unfortunately, using matio is very different from using the Matlab API,
  so i decided to write a drop-in replacement for the file output API.  
  
## Features
  I've only implemented the functionality I need, so the following is 
  currently supported:  
    * writing strings (arrays of chars);  
    * writing arrays of doubles;  
    * writing arrays of complex doubles;  
    * writing structures;  
    * writing arrays of structures;  
    * structure nesting;  
    * appending data to previously created .mat files;  

## Implemented Functions
  All implemented functions have the same name and accept the same
  parameters as their equivalent in the Matlab API.  
  Functions currently implemented:  
    * matOpen()  
    * matClose()  
    * mxCreateString()  
    * mxCreateDoubleMatrix()  
    * mxCreateStructMatrix()  
    * mxSetFieldByNumber()  
    * mxGetImagData()  
    * mxGetPr()  
    * mxGetData()  
    * mxGetPi()  
    * mxCalcSingleSubscript()  
    * matPutVariable()  
    * mxDestroyArray()  
  This set of functions is used on a day-to-day basis as part of a
  research model for underwater acoustics/communications at SiPLAB,
  Universidade do Algarve <http://www.siplab.fct.ualg.pt/>.

  
## Notes:  
  * Matlab V6 files are written.  
  * Currently, only two-dimensional arrays are supported.  
  * Writing of "compressed" arrays is not implemented (this feature only
    benefits arrays made up entirely of integers anyway).  
  * A special method for saving short array names has not been
    implemented (neglected as this only saves 4 bytes).  
  * MatOut is written in C99. I consider this to be a feature, not a
    limitation.  
  * The Matfile format documentation can be found at:
    http://www.mathworks.com/access/helpdesk/help/pdf_doc/matlab/matfile_format.pdf
