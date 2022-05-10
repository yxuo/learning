'''TKinter comes built-in with Python'''

import tkinter as tk

window1 = tk.Tk()
window1.geometry("300x250")
window1.minsize(300,250)
window1.title("Window window1")

# Make window grid responsible:
# set minimum size for all rows and columns

window1.grid_rowconfigure(0, weight=1)
window1.grid_rowconfigure(1, weight=1)

window1.grid_columnconfigure(0, weight=1)
window1.grid_columnconfigure(1, weight=1)

# Creating widgets (button, label, etc)
# 
#    「        Window 1      -□x ˥
#     ----------------------------
#     |0           |1            |
# 0   | --------[label]--------- |
# 1   | --[quit]-- | ---[btn]--- |

label = tk.Label(
    window1,
    text="Responsivess!",
)
label.grid(
    padx=10,
    pady=10,
    row=0,
    column=0,
    columnspan=2,
    # Columnspan
    # col 0   | col 1
    # 1x      | 2x
)

btn = tk.Button(
    window1,
    text="Click me!",
)
btn.grid(
    padx=10,
    pady=10,
    row=1,
    column=0,
)

quit = tk.Button(
    window1,
    text="Quit",
    command=window1.destroy,
)
quit.grid(
    padx=10,
    pady=10,
    row=1,
    column=1,
)


window1.mainloop()

