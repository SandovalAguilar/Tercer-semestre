'''
Ismael Sandoval Aguilar - 2086210
Programacion Orientada a Objetos - 031 A2022
Prof. Jose Luis Candelario Tovar
27 de octubre de 2022
'''

import requests 
from bs4 import BeautifulSoup

URl = "https://www.misprofesores.com/escuelas/UANL-FCFM_2263"
html_doc = requests.get(URl)
soup = BeautifulSoup(html_doc, 'html.parser')


soup.find_all('var dataSet')

