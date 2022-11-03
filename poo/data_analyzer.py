'''
file -- data_analyzer.py -- 
'''

#Librerias y modulos necesarios
import pandas as pd
import matplotlib.pyplot as plt
import html_to_dataframe as td
import numpy as np
from datetime import date

#Clases
class table():

    def __init__(self, table, URL_source):
        self.table = table
        self.URL_source = URL_source

class results():

    def __init__(self, min_table, max_table):
        self.min_table = min_table
        self.max_table = max_table

    def display_all(self):
        print(self.min_table)
        print('\n')
        print(self.max_table)

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

    df = df.table.rename(columns = new_names)

    new_types = {
        'ID' : 'int',
        '# de calif.' : 'int',
        'Promedio' : 'float'
    }

    df = df.astype(new_types)

    null_values = df.loc[df["Promedio"].isnull()]
    df = df.dropna()

    df['Razon'] = df['# de calif.'] / df['Promedio']

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

    final_results = results(resultados_min, resultados_max)

    today_date = str(date.today())

    df.to_csv('fcfm_data_' + today_date + '.csv')

    return final_results

#if __name__ == "__main__":
    #data_analyzer()