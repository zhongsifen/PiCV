from ctypes import *
libPiCV = CDLL("libPiCV.dylib")
libPiCV.PiCV_run()
