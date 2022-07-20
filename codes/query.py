import requests
import json
import urllib3
import random

def ciphertext(x):
	headers = {
		'Origin': 'https://172.27.26.181:9996/',
		'Accept-Encoding': 'gzip, deflate, br',
		'Accept-Language': 'en-IN,en-US;q=0.9,en;q=0.8',
		'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/72.0.3626.119 Safari/537.36',
		'Content-Type': 'text/plain',
		'Accept': '*/*',
		'Referer': 'https://172.27.26.181:9996/game/caves.swf',
		'X-Requested-With': 'ShockwaveFlash/32.0.0.330'	,
		'Connection': 'keep-alive',
	}
	data = '{"password":"141798618b83828d42ab9619284fb5de","teamname":"CMEN","plaintext":"'+str(x)+'"}'
	urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)
	response = requests.post('https://172.27.26.181:9996/eaeae', headers=headers, data=data, verify=False)
	json_data = json.loads(response.content)
	return json_data["ciphertext"]

def enc(c):
	s = bin(c)[2:].zfill(8)
	n = ""
	for i in range(len(s)>>2):
		p = int(s[4*i:4*i+4], 2)
		n += chr(ord('f')+p)
	return n

for row in range(0, 8):

	pref, suff = "", ""
	for i in range(row):
		pref += "ff"
	for i in range(7-row):
		suff += "ff"

	for idx in range(row+1):
		f = open("./input/"+str(row+1)+"/"+str(idx+1)+".txt", "w+")
		
		for P in range(1<<7):
			print(row, idx, P)
			if P:
				f.write("\n")
			a = pref+enc(P)+suff
			f.write(a)
		f.close()
		pref = (pref+"fg")[2:]