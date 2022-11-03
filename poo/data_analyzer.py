'''
Ismael Sandoval Aguilar - 2086210
Programacion Orientada a Objetos - 031 A2022
Prof. Jose Luis Candelario Tovar
27 de octubre de 2022
'''

#Librerias y modulos necesarios
import pandas as pd
import matplotlib.pyplot as plt
import html_to_dataframe as td
import numpy as np

#Clases
class table():

    def __init__(self, table, URL_source):
        self.table = table
        self.URL_source = URL_source

#Programa principal
def data_analyzer():
    URL_site = "https://www.misprofesores.com/escuelas/UANL-FCFM_2263"
    df = table(td.to_dataframe(), URL_site)

    new_names = {
        'i' : 'ID', 
        'n' : 'Nombre', 
        'a' : 'Apellido', 
        'd' : 'Departamento / Facultad',
        'm' : '# de calif.',
        'c' : 'Promedio'
    }

    df = df.rename(columns = new_names)

    new_types = {
        'ID' : 'int',
        '# de calif.' : 'int',
        'Promedio' : 'float'
    }

    df = df.astype(new_types)

    null_values = df.loc[df["Promedio"].isnull()]
    df = df.dropna()

    resultados_max = df.loc[
        (df["Promedio"] > df["Promedio"].mean()) & 
        (df["# de calif."] > df["# de calif."].mean()) & 
        (df['Razon'] > df['Razon'].mean())]

    resultados_max = resultados_max.sort_values(by = "Razon", ascending = False).reset_index(drop = True).head(10)
    resultados_max = resultados_max.sort_values(by = 'Promedio', ascending = False).reset_index(drop = True).head(10)

    resultados_min = df.loc[
        (df["Promedio"] < df["Promedio"].mean()) & 
        (df["# de calif."] > df["# de calif."].mean()) & 
        (df['Razon'] > df['Razon'].mean())]

    resultados_min = resultados_min.sort_values(by = "Razon", ascending = False).reset_index(drop = True).head(10)
    resultados_min = resultados_min.sort_values(by = 'Promedio')

    print(df.table)

if __name__ == "__data_analyzer__":
    data_analyzer()