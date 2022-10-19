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

class Pagina: 

    nombre_sitio = "Mis Profesores"

    def __init__(self, apartado, URL):
        self.apartado = apartado
        self.URL = URL

    def get_HTML(self):
        HTML = requests.get(self.URl, verify = False)
        return HTML

def main():
    URL = "https://www.misprofesores.com/escuelas/UANL-FCFM_2263"
    tabla = Pagina("tabla", str(URL))
    tabla.get_HTML()

if __name__ == "__main__":
    main()

