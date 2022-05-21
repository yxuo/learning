import tkinter as tk

# Config window

window1 = tk.Tk()
window1.title("Window 1")
window1.geometry("400x300")
# window1.iconbitmap("../../../img/tomato.ico")
# window1.resizable(True,True)

# Config widgets

label = tk.Label(
    window1,
    text="Hello World!",
).pack()

quit = tk.Button(
    window1,
    text="Quit",
    command=window1.quit,
).pack()

button = tk.Button(
    window1,
    text="Click me!",
).pack()

# Init window

window1.mainloop()