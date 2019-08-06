# File name: PiMien.py
import kivy
kivy.require('1.7.0')
from kivy.app import App
from kivy.lang import Builder
from kivy.uix.anchorlayout import AnchorLayout

Builder.load_file('toolbox.kv')
Builder.load_file('drawingspace.kv')
Builder.load_file('menubar.kv')
Builder.load_file('statusbar.kv')

class PiMien(AnchorLayout):
    pass


class PiMienApp(App):
    def build(self):
        return PiMien()

if __name__=="__main__":
    PiMienApp().run()
