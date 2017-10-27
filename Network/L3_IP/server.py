import socket
from config import * 


def answer_to_client(message):
	try:
		n = int(message)
	except ValueError as e:
		return "Need to send number of IP-addres"
	
	with open(FILENAME, "r") as f:
		addreses = f.readlines()
	if n > len(addreses) or n <= 0:
		return "Count addreses in file: {0}".format(len(addreses))
	else:
		answer = ""
		answer += ("\nDec: " + addreses[n-1][:-1])
		ans2 = "\nBin: "
		ans8 = "\nOct: "
		ans16 = "\nHex: "
		for oktet in addreses[n-1].split("."):
			ans2 += (bin(int(oktet)) + ".")
			ans8 += (oct(int(oktet)) + ".")
			ans16 += (hex(int(oktet)) + ".")
		answer += (ans2[:-1] + ans8[:-1] + ans16[:-1])
		return answer

def main():
	s = socket.socket()
	s.bind(('', PORT))
	s.listen(1)
	
	try: 
		while True:
			conn, addr = s.accept()
			print "\nNew connection from: " + addr[0] 
			data = conn.recv(MSGLEN)
			if not data:
				break
			print "Number from client: " + data
			answer = answer_to_client(data)
			conn.send(answer)
	except Exception as e:
		print "Socket error: " + str(e)  
	except KeyboardInterrupt as interrupt:
		print "\nServer off"
	finally: 
		conn.close()

if __name__ == '__main__':
	 
	main()