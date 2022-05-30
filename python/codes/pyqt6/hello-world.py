'''
Source:
* Examples PyQT     - https://github.com/pyqt/examples
* Download PyQT6    - https://pypi.org/project/PyQt6/

* Buton click event:
    * PyQT, Widgets - https://github.com/pyqt/examples/blob/_/src/02%20PyQt%20Widgets/main.py
    * STDWorkFlow   - https://stdworkflow.com/21/pyqt6-qt-designer-button-click-event
    * StackOverflow - https://stackoverflow.com/questions/45723284/open-a-window-and-close-a-window-in-pyqt5

> pip install pyqt6

Advantages of PyQT:
⭐ A few lines and everything works!
⭐ The layout is automatically responsive!
'''

# from PyQt6.QtWidgets import *
from PyQt6 import QtWidgets

# app, window

app = QtWidgets.QApplication([])
window1 = QtWidgets.QWidget()
window1.setMinimumSize(400,300)
window1.setWindowTitle("Window 1")

# Window widgets

layout = QtWidgets.QVBoxLayout()
layout.addWidget(QtWidgets.QLabel("Hello World!"))
quit = QtWidgets.QPushButton("Quit")
layout.addWidget(quit)
quit.clicked.connect(QtWidgets.QApplication.quit)

layout.addWidget(QtWidgets.QPushButton("Click me!"))
window1.setLayout(layout)
window1.show()
app.exec()