'''
from ctypes import *
import os
libPiCV = CDLL(os.path.dirname(__file__) + "/../build/PiCV/libPiCV.so")
path = "/home/pi/Data/48.3gp"
cpath = path.encode('utf-8')
libPiCV.cv_setup(None)
libPiCV.cv_run()

# sub-classing the App class
# implementing its build() method so it returns a Widget instance as the root of the widget tree.
# instantiating this class, and calling its run() method.


class CamApp(App):

    def build(self):
        self.img1 = Image()
        layout = BoxLayout()
        layout.add_widget(self.img1)
        Clock.schedule_interval(self.update, 1.0/25.0)

        self.capture = cv2.VideoCapture(0)
        # cv2.namedWindow("CV2 Image")
        return layout

    def update(self, dt):
        ret, frame = self.capture.read()
        # cv2.imshow("CV2 Image", frame)
    
        buf1 = (cv2.flip(frame, 0)).tostring()
        txt1 = Texture.create(size=(frame.shape[1], frame.shape[0]), colorfmt='bgr')
        txt1.blit_buffer(buf1, colorfmt='bgr', bufferfmt='ubyte')
        self.img1.texture = txt1


if __name__ == '__main__':
    CamApp().run()
    cv2.destroyAllWindows()

'''

from kivy.app import App
from kivy.uix.widget import Widget
from kivy.uix.image import Image

class PiCV_Widget(Widget):
    pass


class PiCV_App(App):
    def build(self):
        # self.img1 = Image()
        # layout = BoxLayout()
        # layout.add_widget(self.img1)
        # Clock.schedule_interval(self.update, 1.0/25.0)

        # self.capture = cv2.VideoCapture(0)
        return PiCV_Widget()


if __name__ == '__main__':
    PiCV_App().run()
