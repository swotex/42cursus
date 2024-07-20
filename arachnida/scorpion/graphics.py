import tkinter
import customtkinter

def clear_frame(frame):
    for widget in frame.winfo_children():
        widget.destroy()

def __printImageInfo(image, mainFrame):
	print(image.name)

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