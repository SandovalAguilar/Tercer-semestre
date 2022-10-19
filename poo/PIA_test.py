'''
Ismael Sandoval Aguilar - 2086210
Programacion Orientada a Objetos - 031 A2022
Prof. Jose Luis Candelario Tovar
27 de octubre de 2022
'''

import requests 
from bs4 import BeautifulSoup as bs
import json
import re
import pandas as pd

URl = "https://www.misprofesores.com/escuelas/UANL-FCFM_2263"
page = requests.get(URl, verify = False)

soup = bs(page.content, "html.parser")
raw_json = soup.find_all('script', type = 'text/javascript')
str_json = "[" + re.search(r'{"i.*":\s*"(.*?)"}', str(raw_json)).group() + "]"

str_to_json = json.loads(str_json)
df = pd.json_normalize(str_to_json)

print(df)

#print(str_array)


#[
# {
#   "i":"82556",
#   "n":"Azucena Alejandra",
#   "a":"Aceves Al\u00f3s",
#   "d":"UANL - FCFM (Actuar\u00eda)",
#   "m":"21","c":"8.6190"},
#   }
#]