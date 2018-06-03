import os
import re
import requests


url = r"http://59.51.24.46/hysf/framework/main.jsp"
cookies={'JSESSIONID':'F3F99FEB526349B3915D1D69A5F63F36'}

headers={'User_agent':'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.139 Safari/537.36'}
rep = requests.get(url, headers = headers, cookies = cookies)


print(rep.content.decode('utf-8'))