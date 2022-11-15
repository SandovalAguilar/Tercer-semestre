import unicodedata
import pandas as pd
import html_to_dataframe as td
from bs4 import BeautifulSoup
import requests

def strip_accents(text):
    try:
        text = unicode(text, 'utf-8')
    except NameError: # unicode is a default on python 3 
        pass

    text = unicodedata.normalize('NFD', text)\
           .encode('ascii', 'ignore')\
           .decode("utf-8")

    return str(text)

def piso(num):
    if num%5>0: 
        div=num//5 + 1 
    else:
        div=num//5
    return int(div)

def extractdata(url, profesor):
    datos=[]
    resp = requests.get(url)
    soup = BeautifulSoup(resp.text, 'html.parser')
    for sopita in soup.find_all('tr')[1:]:
        scores=sopita.find(class_='breakdown').find_all(class_='score')
        grade=sopita.find(class_='grade').find(class_='response').text
        datos.append({'profesor' : profesor, 'calidad' : scores[0].text, 'facilidad' : scores[1].text, 'califest' : grade})
    return datos
delta=[]
dat=data_analyzer('https://www.misprofesores.com/escuelas/UANL-FCFM_2263', 'FCFM')
dat["ID"]
for index, row in dat.iterrows():
    for i in range(1,piso(row['# de calif.'])):
        baseurl='https://www.misprofesores.com/profesores/'
        url=baseurl+strip_accents(re.sub(r'\s+', '-', row["Nombre"])+'-'+re.sub(r'\s+', '-', row["Apellido"])+'_'+str(row["ID"])+'?page='+str(i))
        for i in extractdata(url, row["Apellido"]): delta.append(i)

delta=pd.DataFrame(delta)
delta.dropna()
for index, row in delta.iterrows():
    if row['califest']=='N/A':
        print('N/A') 
    elif float(row['califest'])>10:
        row['califest']=float(row['califest'])/10
        print(row['califest'])
delta.to_csv('delta2.csv', index=False)
