from ctypes import *
libPiCV = CDLL("/home/pi/Work/PiCV/build/PiCV/libPiCV.so")
path = "/home/pi/Data/48.3gp"
cpath = path.encode('utf-8')
libPiCV.run(None)
