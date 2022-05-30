'''
Source
* https://stackoverflow.com/questions/110923/how-do-i-close-a-tkinter-window
'''

import tkinter as tk

def quit(root):
    root.destroy()

root = tk.Tk()
tk.Button(root, text="Quit", command=lambda root=root:quit(root)).pack()
root.mainloop()