import requests

options_uri_list = ['mail.ru', 'ya.ru', 'www.rambler.ru', 'www.google.ru', 'www.github.com/',
                    'www.linkedin.com/', 'www.apple.com/']
head_uri_list = ['vk.com', 'www.apple.com', 'www.msn.com']
get_post_uri_list = ['www.google.com', 'www.yandex.ru']


def requests_func(list, method, file):
    with open(file, 'w') as f:
        f.write('Requests with method: ' + method)
        for item in list:
            f.write("\n\n\nRequest to " + item)
            try:
                response = requests.request(method, 'http://' + item, timeout=5)
            except requests.exceptions.RequestException as e:
                f.write("\nException: " + str(e))
            else:
                f.write("\nStatus code:" + str(response.status_code))
                f.write("\nHeaders:")
                f.write(str(response.headers))

if __name__ == '__main__':
    requests_func(options_uri_list, 'OPTIONS', 'options_log.txt')
    requests_func(head_uri_list, 'HEAD', 'head_log.txt')
    requests_func(get_post_uri_list, 'GET', 'get_log.txt')
    requests_func(get_post_uri_list, 'POST', 'post_log.txt')

