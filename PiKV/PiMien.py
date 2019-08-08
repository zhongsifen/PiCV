# File name: PiMien.py
import kivy
kivy.require('1.7.0')
from kivy.app import App
from kivy.lang import Builder
from kivy.uix.anchorlayout import AnchorLayout
from kivy.uix.boxlayout import BoxLayout


class PiMien(AnchorLayout):
    pass


class PiMienApp(App):
    def build(self):
        return PiMien()

if __name__=="__main__":
    PiMienApp().run()
