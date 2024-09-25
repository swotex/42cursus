import argparse
import os
import sys
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin, urlparse

HIGH = 1
MEDIUM = 2
LOW = 3

VERBOSE = False
RECUR = False
DEPTH = 5
PATH = "./data/"
QUIT = False

user_agent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36"
headers = {'User-Agent': user_agent}

wantedImgExt = [".jpg", ".jpeg", ".png", ".gif", ".bmp"]
visitedPages = []
downloadedImages = []

def printHeader():
	print(
		"\033[1;36m           _____            _____ _    _ _   _ _____ _____  \n"
		"     /\\   |  __ \\     /\\   / ____| |  | | \\ | |_   _|  __ \\   /\\ \n"
		"    /  \\  | |__) |   /  \\ | |    | |__| |  \\| | | | | |  | | /  \\ \n"
		"   / /\\ \\ |  _  /   / /\\ \\| |    |  __  | . ` | | | | |  | |/ /\\ \\ \n"
		"  / ____ \\| | \\ \\  / ____ \\ |____| |  | | |\\  |_| |_| |__| / ____ \\ \n"
		" /_/____\\_\\_|_ \\_\\/_/____\\_\\_____|_|__|_|_| \\_|_____|_____/_/    \\_\\ \n"
		"  / ____|  __ \\_   _|  __ \\|  ____|  __ \\ \n"
		" | (___ | |__) || | | |  | | |__  | |__) | \n"
		"  \\___ \\|  ___/ | | | |  | |  __| |  _  / \n"
		"  ____) | |    _| |_| |__| | |____| | \\ \\ \n"
		" |_____/|_|   |_____|_____/|______|_|  \\_\\ \n\n\033[0m"
		"   Images extractor jpg/jpeg/png/gif/bmp \n"
	)

def clear_console():
	if os.name == 'nt':  # For Windows
		os.system('cls')
	else:  # For mac and Linux
		os.system('clear')

def printErrors(level, str):
	if (level == HIGH):
		print('\033[1;31m[Error]\033[0m', end=' : ')
	elif (level == MEDIUM):
		print('\033[1;33m[Warning]\033[0m', end=' : ')
	else:
		print('\033[1;34m[Info]\033[0m', end=' : ')
	print(str)

def getContentUrl(url):
	try:
		response = requests.get(url, headers=headers)

		if response.status_code == 200:
			page_content = response.text
			return(page_content)
		else:
			printErrors(MEDIUM, f"Failed to retrieve the page. Status code: {response.status_code} (skipped)")
			return(False)
	except:
		printErrors(HIGH, f"Can't fetch content : {url}")
		return(False)

def downloadImage(urlImage, baseUrl):
	extension = os.path.splitext(urlparse(urlImage).path)[1]
	if (extension.lower() not in wantedImgExt):
		if (VERBOSE):
			printErrors(LOW, f"Unsupported extension {extension} \n url : {urlImage}")
		return
	if (not urlImage):
		return
	if ("http" not in urlImage):
		urlImage = urljoin(baseUrl, urlImage)
	filename = os.path.basename(urlparse(urlImage).path)
	try:
		response = requests.get(urlImage, headers=headers)

		if response.status_code == 200:
			if (filename in downloadedImages):
				return
			downloadedImages.append(filename)
			with open(os.path.join(PATH, filename), 'wb') as file:
				file.write(response.content)
				if (VERBOSE):
					print(f"\033[1;35m[+] Image is successfully downloaded and saved in {PATH}\033[0m")
		else:
			printErrors(MEDIUM, f"Failed to get image. Status code: {response.status_code} (skipped)")
			return
	except:
		printErrors(HIGH, f"Can't fetch image : {urlImage}")
		return

def getCorrectLink(href, baseUrl):
	if ("http" in href):
		if (urlparse(href).netloc != urlparse(baseUrl).netloc):
			if (QUIT == False):
				return (None)
			if (VERBOSE):
				printErrors(MEDIUM, "The Recursive quited the main domain")
		return (href)
	return (urljoin(baseUrl, href))
	

def getImages(url, DepthCount):
	if (VERBOSE):
		print(f"\033[1;35m[-] Try to get content of {url}", end=' ')
		if (RECUR):
			print(f"Depth : {(DEPTH - DepthCount) + 1}\033[0m")
		else:
			print("\033[0m")
	content = getContentUrl(url)
	if (not content):
		return
	soup = BeautifulSoup(content, 'html.parser')

	for link in soup.find_all('img'):
		imgLink = link.get('src')
		downloadImage(imgLink, url)

	if (DepthCount == 1 or RECUR == False):
		return

	for link in soup.find_all('a'):
		href = link.get('href')
		if (not href or "#" in href):
			continue
		completUrl = getCorrectLink(href, url)
		if (completUrl == None or completUrl in visitedPages):
			continue
		visitedPages.append(completUrl)
		getImages(completUrl, DepthCount - 1)

def main():
	clear_console()
	printHeader()

	global VERBOSE
	global RECUR
	global DEPTH
	global PATH
	global QUIT

	parser = argparse.ArgumentParser(description='Images extractor jpg/jpeg/png/gif/bmp')
	
	parser.add_argument('-r', action='store_true', help='Recursively downloads')
	parser.add_argument('-l', metavar='[DEPTH]', type=int, default=5, help='Maximum depth level to the recursive download. Default 5')
	parser.add_argument('-p', metavar='[PATH]', type=str, default='./data/', help='PATH where downloaded files will be saved. Default (./data/)')
	parser.add_argument('-v', action='store_true', help='Enable verbose mode')
	parser.add_argument('-q', action='store_true', help='Enable to allow exit from primary domain')
	parser.add_argument('URL', type=str, help='URL to download images from')

	args = parser.parse_args()
	
	# Afficher les valeurs des arguments
	if args.p is not None:
		print(f'Path :      {args.p}')
		PATH = args.p
	if args.l is not None:
		print(f'Depth :     {args.l}')
		DEPTH = args.l
	if args.r is not None:
		print(f'Recursive : {args.r}')
		if (args.r):
			RECUR = True
	if args.v is not None:
		print(f'Verbose :   {args.v}')
		if (args.v):
			VERBOSE = True
	if args.q is not None:
		print(f'quit domain :   {args.q} \n')
		if (args.q):
			QUIT = True

	if not os.path.exists(args.p):
		try:
			os.makedirs(args.p)
		except:
			printErrors(HIGH, f"Can't create folder : {args.p}")
			return
		if (VERBOSE):
			printErrors(LOW, f'{args.p} folder are created')
	else:
		if not os.path.isdir(args.p):
			printErrors(HIGH, f'{args.p} is not a valid folder')
			return

	visitedPages.append(args.URL)
	getImages(args.URL, DEPTH)
	print(f"\033[1;32m\n[\u2713] Finished, {len(downloadedImages)} images downloaded in {len(visitedPages)} pages\033[0m\n")


if __name__ == '__main__':
	main()
