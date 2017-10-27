import socket
import sys
from config import * 

def main():
		
	try: 
 		n = int(sys.argv[1])
	except ValueError:
		print "Incorrect format to parametr" 
	except IndexError:
		print  "Set number of IP-address by argv" 
	else:
		try:
			s = socket.socket()
			s.connect((HOST, PORT))
			s.send(str(n))
			data = s.recv(MSGLEN)
			print "Data from server: " + data
		except Exception as e:
			print "Socket error: " + str(e)
		finally:
			s.close()
		

if __name__ == '__main__':
	main()