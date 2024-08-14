import sys
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin

ip = input("site ip = ")

visitedPages = []
allReadme = []

def getContentUrl(session, url):
	try:
		response = session.get(url)

		if response.status_code == 200:
			page_content = response.text
			return(page_content)
		else:
			return(False)
	except:
		return(False)

def getCorrectLink(href, baseUrl):
	if ("http" in href):
		return (href)
	return (urljoin(baseUrl, href))

def getReadme(session, urlFile, baseUrl):
	if (not urlFile):
		return
	urlFile = getCorrectLink(urlFile, baseUrl)
	try:
		response = session.get(urlFile)

		if response.status_code == 200:
			if (response.content not in allReadme):
				allReadme.append(response.content)
				print(response.content)
		else:
			return
	except:
		return

def recursive_search(session, url, DepthCount):
	if (DepthCount == 0):
		return
	content = getContentUrl(session, url)
	if (not content):
		return
	soup = BeautifulSoup(content, 'html.parser')

	for link in soup.find_all('a'):
		href = link.get('href')
		text = link.get_text()
		if (not href or "#" in href or "../" in text or "README" in text):
			if "README" in text:
				getReadme(session, href, url)
			continue
		completUrl = getCorrectLink(href, url)
		if (completUrl in visitedPages):
			continue
		visitedPages.append(completUrl)
		recursive_search(session, completUrl, DepthCount - 1)


url = f"http://{ip}/.hidden/"
visitedPages.append(url)
session = requests.session()
recursive_search(session, url, 4)
print(f"\033[1;32m\n[\u2713] Finished {len(allReadme)} differents readme content in {len(visitedPages)} pages\033[0m\n")
