import socket
import sys
from config import *


if __name__ == "__main__":
	try:
		method = sys.argv[1]
		filename = sys.argv[2]
	except IndexError:
		print "Set method and filename by argv"

	else:
		try:
			s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			s.connect(("", PORT))
			request = method + " /" + filename + " HTTP/1.1"
			s.send(request.encode())
			
			response = s.recv(MSGLEN)
			print "response from server:\n" + response.decode()
 
		except Exception as e:
			print "Socket error: " + str(e)
		finally:
			s.close()