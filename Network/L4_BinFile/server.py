import socket
from config import * 

def main():
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind(('', PORT))
	s.listen(1)
	
	try: 
		while True:
			conn, addr = s.accept()
			print "\nNew connection from: " + addr[0] 
			data = conn.recv(MSGLEN)
			if not data:
				break
			print "Message from client: " + data
			
			try:
				f = open(data, "rb")
			except IOError:
				conn.send("None")
			else:
				while True:
					buf = f.read(MSGLEN)
					if len(buf) == 0:
						print "END"
						conn.send(END_FILE)
						f.close()
						break
					else:
						print "\n\n--> send " + str(len(buf)) + " bytes"
						conn.send(buf)

	except Exception as e:
		print "Socket error: " + str(e)  
	except KeyboardInterrupt:
		print "\nServer off"
	finally: 
		conn.close()

if __name__ == '__main__':
	 
	main()