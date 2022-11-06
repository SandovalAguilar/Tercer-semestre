'''
file -- data_analyzer.py -- 
'''

#Librerias y modulos necesarios
import pandas as pd
import html_to_dataframe as td

#Clases
class table():

    def __init__(self, table, URL_source):
        self.table = table
        self.URL_source = URL_source

class results():

    def __init__(self, min_table, max_table, full_table):
        self.min_table = min_table
        self.max_table = max_table
        self.full_table = full_table

#Programa principal
def data_analyzer(URL_site, facultad):
    
    df = table(td.to_dataframe(URL_site, facultad), URL_site)

    # Nuevos nombres para las columnas
    new_names = {
        'i' : 'ID', 
        'n' : 'Nombre', 
        'a' : 'Apellido', 
        'd' : 'Departamento / Facultad',
        'm' : '# de calif.',
        'c' : 'Promedio'
    }

    df = df.table.rename(columns = new_names)

    # Cambiar el tipo de variale
    new_types = {
        'ID' : 'int',
        '# de calif.' : 'int',
        'Promedio' : 'float'
    }

    df = df.astype(new_types)

    # Eliminar valores nulos
    null_values = df.loc[df["Promedio"].isnull()]
    df = df.dropna()

    # Razon entre el numero de calif. y el promedio
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

    final_results = results(resultados_min, resultados_max, df)

    # Se retorna un objeto con los dataframes resultantes
    return final_results

#Este apartado solo debe utilizarse para realizar pruebas individuales del modulo
'''
if __name__ == "__main__":
    
    input_url = input()
    nombre_facultad = input()
    print(data_analyzer(input_url, nombre_facultad).full_table)
'''