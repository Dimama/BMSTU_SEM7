from config import * 
import socket
import signal
import time

class Server:
	def __init__(self, port=PORT, host='', pages_dir=DIR):
		self.port = port
		self.host = host
		self.pages_dir = pages_dir

	def run_server(self):
		self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
		
		try:
			self.socket.bind((self.host, self.port))
		except Exception as e:
			print "Could not run server on port: " + str(self.port)
			self.stop_server()
		else:
			print "Server running on: "  + str(self.port)
			print "Press ctrl+c to stop server"
			self.wait_for_connection()


	def stop_server(self):
		try:
			self.socket.shutdown(socket.SHUT_RDWR)
		except Exception as e:
			print "Can't stop server with error: " + str(e)
		else:
			print "Server was stopped"


	def wait_for_connection(self):
		print "Wait for new connections:"
		self.socket.listen(5)		
		while True:
			conn, addr = self.socket.accept()
			print "\n\n------------\nNew connection from: " + str(addr)

			data = conn.recv(MSGLEN)
			string = bytes.decode(data)
			method = string.split(' ')[0].split('?')[0]
			print "Request from client: " + string

			response = ""			
			if method == "HEAD" or method == "GET":
				f = None
				file_req = string.split(' ')[1]
				if file_req == "/":
					file_req = "/index.html"
				try:
					f = open(DIR + file_req, "rb")
				except IOError:
					response = self.gen_headers(CODES["Not Found"]).encode()
					if method == "GET":
						response += (b"<html><body><p>Error 404: File not found</p><p>Python HTTP server</p></body></html>")
					
				else:
					response = self.gen_headers(CODES["OK"]).encode()
					if method == "GET":
						response += (f.read())
					
				finally:
					if f is not None:
						f.close()				
				
			else:
				response = self.gen_headers(CODES["Not Implemented"]).encode()
				print response
				
			conn.send(response)
			conn.close()
			print "Closed connection with client"

	def gen_headers(self, code):
		
		headers = "HTTP/1.1 " + str(code)
		if code == 200:
			headers += " OK\n"
		if code == 404:
			headers += " Not Found\n"
		if code == 501:
			headers += " Not Implemented\n"

		current_date = time.strftime("%a, %d %b %Y %H:%M:%S", time.localtime())
		headers += "Date: " + current_date +"\n"
		headers += "Server: Python-HTTP-Server\n"
		headers += "Connection: close\n\n"

		return headers			

def shutdown(sig, dummy):
	s.stop_server()	
	import sys
	sys.exit(1)

if __name__ == "__main__":

	signal.signal(signal.SIGINT, shutdown)

	print "Start web server..."
	s = Server()
	s.run_server()
	