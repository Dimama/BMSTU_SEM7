import smtplib 
import password

def make_email_text(subject, body, sender, reciever):
	return 'From: {0}\nTo: {1}\nSubject: {2}\n\n\n{3}'.format(
							  sender, reciever, subject, body)
							   
def send_messages(address, messages):
	sender = 'dima03130@gmail.com'
	try:  
		server = smtplib.SMTP_SSL('smtp.gmail.com', 465)
		server.ehlo()
		server.login(sender, password.PASSWORD)
		for message in messages:
			email_text = make_email_text('Lab7 on Python with Google SMTP',
										 message, sender, address)    		
			server.sendmail(sender, address, email_text)
		server.close()
		print ('Messages successful send!')
	except Exception as e:  
		print ('Error of sending messages: ' + str(e))
