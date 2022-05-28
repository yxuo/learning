'''
Source:
* Tkinter radio button  - https://www.pythontutorial.net/tkinter/tkinter-radio-button/
* Esc to quit window    - https://www.tutorialspoint.com/how-to-bind-the-escape-key-to-close-a-window-in-tkinter
* Entry read only       - https://stackoverflow.com/questions/3842155/is-there-a-way-to-make-the-tkinter-text-widget-read-only
'''

import tkinter as tk
from tkinter import messagebox

win = tk.Tk()
win.eval('tk::PlaceWindow . center')
win.title("Calculadora rústica")
# win.geometry("300x200")
win.bind("<Escape>", lambda e: win.quit())

win.grid_columnconfigure(0, weight=0)
win.grid_columnconfigure(1, weight=0)
win.grid_columnconfigure(2, weight=0)
win.grid_columnconfigure(3, weight=0)
win.grid_columnconfigure(4, weight=0)
win.grid_columnconfigure(5, weight=0)
win.grid_columnconfigure(6, weight=0)

win.grid_rowconfigure(0, weight=0)
win.grid_rowconfigure(1, weight=0)
win.grid_rowconfigure(2, weight=1)


def set_info(txt, color="black"):
    win_text.config(state=tk.NORMAL, disabledforeground=color)
    win_text.delete(0, tk.END)
    win_text.insert(0, txt)
    win_text.config(state=tk.DISABLED)


def calc():
    num1 = win_entry_n1.get()
    num2 = win_entry_n2.get()

    if not num1 or not num2:
        set_info("Empty entry!", "red")
        return
    if not num1.isdecimal() or not num2.isdecimal():
        set_info("Invalid entry!", "red")
        return

    num1 = int(num1)
    num2 = int(num2)

    op = win_radio_op.get()
    ret = 0
    if op == "+":
        ret = num1+num2
    if op == "-":
        ret = num1-num2
    if op == "*":
        ret = num1*num2
    if op == "/":
        ret = num1/num2
    
    set_info("%.1f"%ret)


# row 0
win_h1 = tk.Label(win, text="Calculadora rústica", font=("", 20))
win_h1.grid(sticky="nsew", columnspan=2, row=0, column=0)

# roow 1
win_label_n1 = tk.Label(win, text="Digite um número")
win_label_n1.grid(row=1, column=0)

win_entry_n1 = tk.Entry(win)
win_entry_n1.grid(row=1, column=1, padx=10)
# win_entry_n1.insert(0, "2")

# row 2
win_label_n2 = tk.Label(win, text="Digite um outro número")
win_label_n2.grid(row=2, column=0)

win_entry_n2 = tk.Entry(win)
win_entry_n2.grid(row=2, column=1, padx=10)
# win_entry_n2.insert(0, "3")

# row 3
win_radio_op = tk.StringVar(value="+")
radio1 = tk.Radiobutton(win, text="+", value="+", variable=win_radio_op)
radio1.grid(row=3, column=0)
radio2 = tk.Radiobutton(win, text="-", value="-", variable=win_radio_op)
radio2.grid(row=3, column=1)

# row 4
radio3 = tk.Radiobutton(win, text="*", value="*", variable=win_radio_op)
radio3.grid(row=4, column=0)
radio4 = tk.Radiobutton(win, text="/", value="/", variable=win_radio_op)
radio4.grid(row=4, column=1)

# row 5
win_btn_calc = tk.Button(win, text="Calcular operação", width=42, command=calc)
win_btn_calc.grid(row=5, column=0, columnspan=3, padx=10)

# row 6 - footer
win_label_footer = tk.Label(win, text="Resultado")
win_label_footer.grid(row=6, column=0)

win_text = tk.Entry(win, text="0", state=tk.DISABLED)
win_text.grid(row=6, column=1)

win.mainloop()
