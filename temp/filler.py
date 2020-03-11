def close():
    root.destroy()
    root.quit()

WIDTH = 800
HEIGHT = 800
TITLE = "Filler"
BACKGROUND_COLOR = "black"
GRID_COLOR = "white"
PLAYER_COLOR = "blue"
RIVAL_COLOR = "red"

class Menu:
    def __init__(self, core):
        pass

class Field:
    def __init__(self, core):
        self.canvas = tk.Canvas(core, bg=BACKGROUND_COLOR)
        self.canvas.pack()

class Filler:
    def __init__(self, master):
        self.master = master
        self.master.geometry(f"{WIDTH}x{HEIGHT}")
        self.master.title(TITLE)
        self.gui_init()

    def gui_init(self):
        self.master.rowconfigure(0, weight=1)
        self.master.columnconfigure(0, weight=1)
        self.core_frame = tk.Frame(self.master)
        self.field_frame = tk.Frame(self.core_frame)
        self.field = Field(self.field_frame)
        self.menu_frame = tk.Frame(self.core_frame)
        self.core_frame.pack()
        self.field_frame.grid(row=0, column=0, sticky=tk.NSEW)
        

    def canvas_init(self):
        pass

import tkinter as tk
root = tk.Tk()
gui = Filler(root)
root.mainloop()
