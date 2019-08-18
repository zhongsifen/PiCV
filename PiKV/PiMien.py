# File name: PiMien.py
import kivy
kivy.require('1.7.0')
from kivy.app import App
from kivy.lang import Builder
from kivy.uix.widget import Widget
from kivy.uix.anchorlayout import AnchorLayout
from kivy.uix.image import Image
from kivy.uix.camera import Camera
from kivy.graphics.texture import Texture

from kivy.config import Config
Config.set('graphics', 'width',  '960')
Config.set('graphics', 'height', '960')

class PiMien(AnchorLayout):
    
    def __init__(self, **kwargs):
        super(PiMien, self).__init__(**kwargs)
        self.img = None
        self.cam = None
        self.sz = None

    def PiStart(self, instance):
        self.cam = self.ids._camera.texture
        self.sz = self.cam.size
        self.ids._image.texture = Texture.create(size=self.sz, colorfmt='rgba', bufferfmt='ubyte')
        self.img = self.ids._image.texture
    

    def PiPlay(self, instance):
        self.ids._camera.play = True

    def PiPause(self, instance):
        self.ids._camera.play = False

    def PiStop(self, instance):
        self.ids._camera.stop()

    def PiRefresh(self, instance):
        self.img.blit_buffer(pbuffer=self.cam.pixels, size=self.sz, colorfmt='rgba', bufferfmt='ubyte')
            # size=self.camera.texture.size, colorfmt=self.camera.texture.colorfmt, bufferfmt='ubyte')
        # self.ids._image.texture.blit_buffer(pbuffer=self.ids._camera.texture.pixels,
        #                                     size=self.camera.texture.size, colorfmt=self.camera.texture.colorfmt, bufferfmt='ubyte')
        #     size=(frame.shape[1], frame.shape[0]), colorfmt='bgr')
        # image_texture.blit_buffer(buf, colorfmt='bgr', bufferfmt='ubyte')
        # # display image from the texture
        # self.texture = image_texture

class PiMienApp(App):
    def build(self):
        return PiMien()

if __name__=="__main__":
    PiMienApp().run()
