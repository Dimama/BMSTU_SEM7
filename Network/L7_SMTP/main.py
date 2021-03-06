import sys
from smtp import send_messages

def get_text(filename):
	with open(filename, "r") as f:
		return f.read()

def sort_by_substr_count(inputStr, word):
	return get_word_count(inputStr, word)

def make_sorted_list_to_send(unsortedList, word):
	unsortedList.sort(key=lambda text: sort_by_substr_count(text, word), reverse=True)
	res = [text for text in unsortedList if get_word_count(text, word) > 0]
	return res

def get_word_count(string, word):
	return string.lower().count(word.lower())

def main():
	try:
		address = sys.argv[1]
		word = sys.argv[2]
		file1 = sys.argv[3]
		file2 = sys.argv[4]
		file3 = sys.argv[5]
	except IndexError:
		print ('Set mail, key_word, text1, text2, text3 by argv')
		return

	allMessages = list(map(get_text, [file1, file2, file3]))
	listToSend = make_sorted_list_to_send(allMessages, word)
	send_messages(address, listToSend)

if __name__ == "__main__":
	main()
