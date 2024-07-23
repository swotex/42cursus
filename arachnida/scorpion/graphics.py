import tkinter
import customtkinter
from PIL import ImageTk, Image

def clear_frame(frame):
	for widget in frame.winfo_children():
		widget.destroy()

def __printImageInfo(image, mainFrame):
	clear_frame(mainFrame)

	my_image = customtkinter.CTkImage(light_image=Image.open(image.imgLink),
                                  dark_image=Image.open(image.imgLink),
                                  size=(150, 150))

	label = customtkinter.CTkLabel(mainFrame, image=my_image, text="")
	label.place(x=10, y=10)

	labelName = customtkinter.CTkLabel(mainFrame, text="Name :", font=("Arial", 16))
	labelName.place(x=180, y=20)
	entryName = customtkinter.CTkEntry(mainFrame, placeholder_text=image.name, width=300, state="disabled")
	entryName.place(x=240, y=20)

	labelSize = customtkinter.CTkLabel(mainFrame, text="Size :", font=("Arial", 16))
	labelSize.place(x=180, y=65)
	entrySize = customtkinter.CTkEntry(mainFrame, placeholder_text=image.getFileSize(), width=80)
	entrySize.place(x=240, y=65)
	labelSize2 = customtkinter.CTkLabel(mainFrame, text="bytes", font=("Arial", 16))
	labelSize2.place(x=330, y=65)

def createWindow(allFiles):
	width = 850
	height = 500

	root = customtkinter.CTk()
	root.geometry(f"{width}x{height}")
	root.title("Scorpion")
	root.resizable(False, False)

	sidebar_frame = customtkinter.CTkScrollableFrame(root, width=160, height=height, corner_radius=0)
	sidebar_frame.grid(row=0, column=0, rowspan=4, sticky="nsew")



	entry = customtkinter.CTkFrame(root, width=(width - 160 - 40), height=(height - 40))
	entry.grid(row=3, column=1, columnspan=2, padx=(20, 0), pady=(20, 20), sticky="nsew")


	for index, image in enumerate(allFiles, start=1):
		button = customtkinter.CTkButton(sidebar_frame, text=image.name[:10], command=lambda img=image, frame=entry: __printImageInfo(img, frame))
		button.grid(row=index, column=0, padx=10, pady=5)
	
	
	root.mainloop()