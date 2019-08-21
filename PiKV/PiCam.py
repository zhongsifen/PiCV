# File name: PiCam.py
from kivy.uix.camera import Camera
from PIL import Image as Img

class PiCam(Camera):

    def pil(self):
        img = Img.frombytes(mode='RGBA', size=self.texture.size, data=self.texture.pixels)
        return img
