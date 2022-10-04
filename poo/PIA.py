'''
Ismael Sandoval Aguilar - 2086210
Programacion Orientada a Objetos - 031 A2022
Prof. Jose Luis Candelario Tovar
27 de octubre de 2022
'''

import requests 

URl = "https://www.misprofesores.com/escuelas/UANL-FCFM_2263"
page = requests.get(URl)

print(page.text)

