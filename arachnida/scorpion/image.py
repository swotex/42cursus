from PIL import Image
import os
from PIL.ExifTags import TAGS
import mimetypes
import datetime

class ImageInfo:
	def __init__(self, imgLink):
		self.imgLink = imgLink
		self.image = Image.open(imgLink)
		self.name = file_name = os.path.basename(imgLink)

	def getImageSize(self):
		width, height = self.image.size
		return str(width) + 'x' + str(height)

	def getFormat(self):
		return self.image.format

	def getFileSize(self):
		return os.path.getsize(self.imgLink)

	def getCreateTime(self):
		return datetime.datetime.fromtimestamp(os.path.getctime(self.imgLink))

	def getModifyTime(self):
		return datetime.datetime.fromtimestamp(os.path.getmtime(self.imgLink))

	def getMimeType(self):
		return mimetypes.guess_type(self.imgLink)

	def getExif(self):
		exif_data = self.image._getexif()

		if exif_data:
			exif = {
				TAGS.get(tag, tag): value
				for tag, value in exif_data.items()
			}
			return exif
		else:
			return None

	def printAll(self):
		print(f"File: {self.imgLink}")
		print(f"  Size: {self.getFileSize()} bytes")
		print(f"  Dimensions: {self.getImageSize()}")
		print(f"  Format: {self.getFormat()}")
		print(f"  MIME type: {self.getMimeType()}")
		print(f"  Creation time: {self.getCreateTime()}")
		print(f"  Modification time: {self.getModifyTime()}")
		print(f"  EXIF data: {self.getExif()}")
