import tkinter
import customtkinter
import os
from PIL import ImageTk, Image
import piexif

def clear_frame(frame):
	for widget in frame.winfo_children():
		widget.destroy()

def on_mousewheel(event, canvas):
	x, y = event.x_root, event.y_root

	frame_x = canvas.winfo_rootx()
	frame_y = canvas.winfo_rooty()
	frame_w = canvas.winfo_width()
	frame_h = canvas.winfo_height()

	if frame_x <= x <= frame_x + frame_w and frame_y <= y <= frame_y + frame_h:
		if event.num == 4 or event.delta > 0:
			canvas._parent_canvas.yview("scroll", -1, "units")
		elif event.num == 5 or event.delta < 0:
			canvas._parent_canvas.yview("scroll", 1, "units")

def __printImageInfo(image, mainFrame):
	clear_frame(mainFrame)

	my_image = customtkinter.CTkImage(light_image=Image.open(image.imgLink),
								  dark_image=Image.open(image.imgLink),
								  size=(180, 180))

	label = customtkinter.CTkLabel(mainFrame, image=my_image, text="")
	label.place(x=10, y=10)

	labelName = customtkinter.CTkLabel(mainFrame, text="Name :", font=("Arial", 16))
	labelName.place(x=210, y=10)
	labelName2 = customtkinter.CTkLabel(mainFrame, text=image.name, font=("Arial", 16))
	labelName2.place(x=270, y=10)

	labelSize = customtkinter.CTkLabel(mainFrame, text="Size :", font=("Arial", 16))
	labelSize.place(x=210, y=40)
	labelSize2 = customtkinter.CTkLabel(mainFrame, text=f"{image.getFileSize()} bytes", font=("Arial", 16))
	labelSize2.place(x=270, y=40)

	labelDimention = customtkinter.CTkLabel(mainFrame, text="Dimention :", font=("Arial", 16))
	labelDimention.place(x=210, y=70)
	labelDimention2 = customtkinter.CTkLabel(mainFrame, text=f"{image.getImageSize()} pixels", font=("Arial", 16))
	labelDimention2.place(x=310, y=70)

	labelFormat = customtkinter.CTkLabel(mainFrame, text="Format :", font=("Arial", 16))
	labelFormat.place(x=210, y=100)
	labelFormat2 = customtkinter.CTkLabel(mainFrame, text=image.getFormat(), font=("Arial", 16))
	labelFormat2.place(x=310, y=100)

	labelCreateTime = customtkinter.CTkLabel(mainFrame, text="Creation time :", font=("Arial", 16))
	labelCreateTime.place(x=210, y=130)
	labelCreateTime2 = customtkinter.CTkLabel(mainFrame, text=image.getCreateTime(), font=("Arial", 16))
	labelCreateTime2.place(x=340, y=130)

	labelModifTime = customtkinter.CTkLabel(mainFrame, text="Modification time :", font=("Arial", 16))
	labelModifTime.place(x=210, y=160)
	labelModifTime2 = customtkinter.CTkLabel(mainFrame, text=image.getModifyTime(), font=("Arial", 16))
	labelModifTime2.place(x=360, y=160)

	# Exif part

	exif = image.getExif()

	exif_frame = customtkinter.CTkScrollableFrame(mainFrame, width=600, corner_radius=10)
	if os.name == 'nt':  # For Windows
		exif_frame.bind_all("<MouseWheel>", lambda event: on_mousewheel(event, exif_frame))
	else:  # For mac and Linux
		exif_frame.bind_all("<Button-4>", lambda event: on_mousewheel(event, exif_frame))
		exif_frame.bind_all("<Button-5>", lambda event: on_mousewheel(event, exif_frame))

	exif_frame.place(x=10, y=210)

	row = 0
	column = 0

	for name, value in exif.items():
		default_value = tkinter.StringVar(value=value)
		customtkinter.CTkLabel(exif_frame, text=name, font=("Arial", 16)).grid(row=row, column=0, padx=10, sticky="w")
		customtkinter.CTkEntry(exif_frame, textvariable=default_value).grid(row=row, column=1, padx=10, sticky="w")
		# print(f"{name} : {value} -> {row} : {column}")
		# if (column == 2):
			# column = 0
		row += 1
		# else:
			# column += 2
	save = customtkinter.CTkButton(mainFrame, text="Save")
	save.place(x=500, y=450)

	print(piexif.load(image.image.info['exif']))

def createWindow(allFiles):
	width = 850
	height = 530

	root = customtkinter.CTk()
	root.geometry(f"{width}x{height}")
	root.title("Scorpion")
	root.resizable(False, False)

	sidebar_frame = customtkinter.CTkScrollableFrame(root, width=160, height=height, corner_radius=0)
	sidebar_frame.grid(row=0, column=0, rowspan=4, sticky="nsew")
	if os.name == 'nt':  # For Windows
		sidebar_frame.bind_all("<MouseWheel>", lambda event: on_mousewheel(event, sidebar_frame))
	else:  # For mac and Linux
		sidebar_frame.bind_all("<Button-4>", lambda event: on_mousewheel(event, sidebar_frame))
		sidebar_frame.bind_all("<Button-5>", lambda event: on_mousewheel(event, sidebar_frame))



	entry = customtkinter.CTkFrame(root, width=(width - 160 - 40), height=(height - 40))
	entry.grid(row=3, column=1, columnspan=2, padx=(20, 0), pady=(20, 20), sticky="nsew")


	for index, image in enumerate(allFiles, start=1):
		button = customtkinter.CTkButton(sidebar_frame, text=image.name[:10], command=lambda img=image, frame=entry: __printImageInfo(img, frame))
		button.grid(row=index, column=0, padx=10, pady=5)

	__printImageInfo(allFiles[0], entry)
	
	
	root.mainloop()