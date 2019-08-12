# File name: PiMien.py
import kivy
kivy.require('1.7.0')
from kivy.app import App
from kivy.lang import Builder
from kivy.uix.widget import Widget
from kivy.uix.anchorlayout import AnchorLayout
from kivy.uix.camera import Camera


class PiMien(AnchorLayout):
    def PiPlay(self, instance):
        self.ids._camera.play = True

    def PiPause(self, instance):
        self.ids._camera.play = False

    def PiStop(self, instance):
        self.ids._camera.stop()


class PiMienApp(App):
    def build(self):
        return PiMien()

if __name__=="__main__":
    PiMienApp().run()
