import urllib2
from bs4 import BeautifulSoup
wiki = "https://en.wikipedia.org/wiki/United_States"

page = urllib2.urlopen(wiki)
soup = BeautifulSoup(page,"lxml")
right_table = soup.find_all(lambda tag: tag.name=='table' and tag.get('class')==['infobox'])
A=[]
B=[]
C=[]
D=[]
E=[]
F=[]
G=[]
for row in right_table[1].findAll("tr"):
    cells = row.findAll('td') #To store second column data
    if len(cells)==5: #Only extract table body not heading
        A.append(cells[0].find(text=True))
        B.append(cells[1].find(text=True))
        C.append(cells[2].find(text=True))
        D.append(cells[3].find(text=True))
        E.append(cells[4].find(text=True))

import pandas as pd
df=pd.DataFrame(A,columns=['Rank'])
df['City']=B
df['Area_Population']=C
df['Statistical_Area']=D
df['Region']=E

from IPython.display import display,HTML

display(df)