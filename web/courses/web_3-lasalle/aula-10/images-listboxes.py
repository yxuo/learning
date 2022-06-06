"""
You need to get the images for this to run.
"""

import tkinter as tk
from PIL import ImageTk, Image
import mysql.connector

#tk
win = tk.Tk()
win.geometry("400x500")
win.iconbitmap("../../../../img/tomato.ico")
win.title("Tomate")

# jpg image - PIL
# win_img_jpg = ImageTk.PhotoImage(Image.open("../../../../img/stock-200.jpg")).
# win_label_img = tk.Label(win,image=win_img_jpg)
# win_label_img.pack()

# png image - tk
win_img_png = tk.PhotoImage(file="../../../../img/stock-200.png")
win_label_img = tk.Label(win,image=win_img_png)
win_label_img.pack()

# chechboxes
win_label_check_country = tk.Label(
    text="Choose your country l1",
    bg="black",
    fg="white",
    font=("Courier",20),
)
win_label_check_country.pack()

win_check_br = tk.Checkbutton(win, text="Brazil", bg="darkgreen",fg="white").pack()
win_check_us = tk.Checkbutton(win, text="US").pack()
win_check_ru = tk.Checkbutton(win, text="Russia").pack()
win_check_cN = tk.Checkbutton(win, text="China").pack()

# list box
win_list = tk.Listbox(win,selectmode="EXTENDED")
win_list.pack()

win_list.insert(win_list.size(),"Cavalo")
win_list.insert(win_list.size(),"Boi")
win_list.insert(win_list.size(),"Baleia")
win_list.insert(win_list.size(),"Veado")

#list 2
win_list_2 = tk.Listbox(win,selectmode="EXTENDED",selectbackground="blue")
win_list_2.pack()
animals = ["horse", "donkey", "whale", "deer"]
[win_list_2.insert(win_list_2.size(),i) for  i in animals]

win.mainloop()