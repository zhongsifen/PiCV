from ctypes import *
libPiCV = CDLL("/Users/zhongsifen/Work/PiCV/build/PiCV/libPiCV.dylib")
path = "/Users/zhongsifen/Data/48.3gp"
cpath = path.encode('utf-8')
cpath = None
libPiCV.run(cpath)
