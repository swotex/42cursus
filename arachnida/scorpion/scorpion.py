import argparse
import os
import sys
from urllib.parse import urlparse
from PIL import Image
from PIL.ExifTags import TAGS
from image import ImageInfo
from graphics import *


def printHeader():
	print(
		"\033[1;36m           _____            _____ _    _ _   _ _____ _____ \n"
		"     /\\   |  __ \\     /\\   / ____| |  | | \\ | |_   _|  __ \\   /\\ \n"
		"    /  \\  | |__) |   /  \\ | |    | |__| |  \\| | | | | |  | | /  \\ \n"
		"   / /\\ \\ |  _  /   / /\\ \\| |    |  __  | . ` | | | | |  | |/ /\\ \\ \n"
		"  / ____ \\| | \\ \\  / ____ \\ |____| |  | | |\\  |_| |_| |__| / ____ \\ \n"
		" /_/____\\_\\_|__\\_\\/_/ ___\\_\\_____|_|__|_|_|_\\_|_____|_____/_/    \\_\\ \n"
		"  / ____|/ ____/ __ \\|  __ \\|  __ \\_   _/ __ \\| \\ | | \n"
		" | (___ | |   | |  | | |__) | |__) || || |  | |  \\| | \n"
		"  \\___ \\| |   | |  | |  _  /|  ___/ | || |  | | . ` | \n"
		"  ____) | |___| |__| | | \\ \\| |    _| || |__| | |\\  | \n"
		" |_____/ \\_____\\____/|_|  \\_\\_|   |_____\\____/|_| \\_| \n\n\033[0m"
		"   Extractor data of images \n"
	)

HIGH = 1
MEDIUM = 2
LOW = 3

VERBOSE = False

autorizedExt = [".jpg", ".jpeg", ".png", ".gif", ".bmp"]
allFiles = []

def printErrors(level, str):
	if (level == HIGH):
		print('\033[1;31m[Error]\033[0m', end=' : ')
	elif (level == MEDIUM):
		print('\033[1;33m[Warning]\033[0m', end=' : ')
	else:
		print('\033[1;34m[Info]\033[0m', end=' : ')
	print(str)

def clear_console():
	if os.name == 'nt':  # For Windows
		os.system('cls')
	else:  # For mac and Linux
		os.system('clear')

def getAllfiles(inFiles, path):
	for file in inFiles:
		extension = os.path.splitext(urlparse(file).path)[1]
		if (extension.lower() in autorizedExt):
			try:
				allFiles.append(ImageInfo(file))
			except Exception as e:
				printErrors(HIGH, f"Error processing file {file}: {e}")

	if (path is None):
		return
	if (not os.path.isdir(path)):
		if (VERBOSE):
			printErrors(MEDIUM, f"{path} is not a directory (skipped)")
		return
	for entry in os.listdir(path):
		full_path = os.path.join(path, entry)
		if os.path.isfile(full_path):
			extension = os.path.splitext(urlparse(full_path).path)[1]
			if (extension.lower() in autorizedExt):
				try:
					allFiles.append(ImageInfo(full_path))
				except Exception as e:
					printErrors(HIGH, f"Error processing file {file}: {e}")
			

def main():
	clear_console()
	printHeader()

	global VERBOSE
	global allFiles

	parser = argparse.ArgumentParser(description='Images extractor data and exif')
	
	parser.add_argument('-f', metavar='[PATH]', type=str, help='Folder of images')
	parser.add_argument('-v', action='store_true', help='Enable verbose mode')
	parser.add_argument('FILES', nargs='*', help='List of image files')

	args = parser.parse_args()

	if args.f is not None:
		print(f'Path :      {args.f}')
		PATH = args.f
	if args.v is not None:
		print(f'Verbose :   {args.v}')
		if (args.v):
			VERBOSE = True
	if args.FILES is not None and len(args.FILES) != 0:
		print(f"Files :      {args.FILES} \n")
	
	getAllfiles(args.FILES, args.f)
	for file in allFiles:
		try:
			pass
			# file.printAll()

		except Exception as e:
			printErrors(HIGH, f"Error processing file {file}: {e}")

	createWindow(allFiles)

if __name__ == '__main__':
	main()
