import socket
import sys
from config import * 
import os

def main():
		
	try: 
 		filename = sys.argv[1]
	except IndexError:
		print  "Set filename by argv"
 
	else:
		try:
			s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			s.connect((HOST, PORT))
			s.send(filename)
			count = 0
			new_name = filename.split(".")[0] + "_new." + filename.split(".")[1]
			f = open(new_name, "wb")

			while True:
				data = s.recv(MSGLEN)
				if data == "None":
					print "File not found on server"
					f.close()
					os.remove(new_name)
					break
				else:
					count += 1
					print "Message #" + str(count) + " from server was recieved"
					if END_FILE in data:
						f.write(data[:-len(END_FILE)])
						f.close()
						print "\nFile was recieved"
						break
					else:
						f.write(data)

		except Exception as e:
			print "Socket error: " + str(e)
		finally:
			s.close()
		

if __name__ == '__main__':
	main()