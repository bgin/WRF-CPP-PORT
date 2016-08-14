# WRF-CPP-PORT
This is an attempt to port to C++ a part of famous Weather Research and Forecasting model written in FORTRAN 90. 
The work on code porting just only started. I concentrated my effort on Physics library first.
The most complicated problem will surely be identification of objects in usually structural and
procedural code which is based on FORTRAN subroutines wrapped in modules and converting it to
modern C++ which in turn will be based solely on generic pprogrammic as much as possible.
