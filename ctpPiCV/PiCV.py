import os
libPiCV = CDLL(os.path.dirname(__file__) + "/../build/PiCV/libPiCV.so")
path = "/home/pi/Data/48.3gp"
cpath = path.encode('utf-8')
libPiCV.run(None)
