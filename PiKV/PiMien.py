# File name: PiMien.py
from PIL import Image as PILImage

import kivy
kivy.require('1.7.0')
from kivy.app import App
from kivy.lang import Builder
from kivy.uix.widget import Widget
from kivy.uix.anchorlayout import AnchorLayout
from kivy.uix.image import Image
from kivy.uix.camera import Camera
from kivy.graphics.texture import Texture
from PiCam import PiCam

from kivy.config import Config
Config.set('graphics', 'width',  '960')
Config.set('graphics', 'height', '960')


class PiMien(AnchorLayout):
    
    def PiStart(self, instance):
        self.cam = self.ids._camera
        self.sz = self.cam.resolution
        print(self.sz)
        self.img = self.ids._image.texture = Texture.create(size=self.sz, colorfmt='rgba', bufferfmt='ubyte')
    
    def PiPlay(self, instance):
        self.ids._camera.play = True

    def PiPause(self, instance):
        self.ids._camera.play = False

    def PiStop(self, instance):
        self.ids._camera.stop()

    def PiRefresh(self, instance):
        # self.img.blit_buffer(pbuffer=self.cam.texture.pixels, size=self.sz, colorfmt='rgba', bufferfmt='ubyte')
        # self.pil = PILImage.frombytes(mode='RGBA', size=self.cam.size, data=self.cam.texture.pixels)
        self.pil = self.ids._camera.pil()
        self.pil.show()

class PiMienApp(App):
    def build(self):
        return PiMien()

if __name__=="__main__":
    PiMienApp().run()
