import urllib2
import re
import sys
from optparse import OptionParser
from bs4 import BeautifulSoup
parser = OptionParser()
if(len(sys.argv)>1):
    parser.add_option('-m', '--movie', dest='movie', help='Movie Name')
    (options, args) = parser.parse_args()
    inp = options.movie
else:
    inp = raw_input("Enter Movie Name: ")
done = []
wiki = ("https://www.bing.com/search?q={0}".format(inp)).replace(" ","+")
#print wiki
listA = ["Movie","Tv Show","Anime"]
page = urllib2.urlopen(wiki)
soup = BeautifulSoup(page,"lxml")
element = soup.find_all(lambda tag: tag.name=='td' and tag.get('class')==['b_rTxt'])
element1 = soup.find_all('div', attrs={'class':'b_lBottom b_snippet'})
#print element1
flag = True
if len(element)!=0 and len(element1)!=0:    
        a = element[0]
        b = element1[0]
        flag = False
        s = a.text.strip()
        s1 = b.text
        if '/' in s:
            print "IMDB Rating : "+s
            done.append(s)
            print "---------------------------------************--------------------------------------"
            print s1
            print "---------------------------------************--------------------------------------"

for k in range(3):
    wiki = ("https://www.bing.com/search?q={0}".format(inp)+"+"+listA[k]).replace(" ","+")
    page = urllib2.urlopen(wiki)
    soup = BeautifulSoup(page,"lxml")
    element1 = soup.find_all('div', attrs={'class':'b_lBottom b_snippet'})
    element = soup.find_all(lambda tag: tag.name=='td' and tag.get('class')==['b_rTxt'])
    if len(element)!=0 and len(element1)!=0:
        a = element[0]
        b = element1[0]
        flag = False
        s = a.text.strip()
        s1 = b.text
        if ('/' in s) and (s not in done):
            done.append(s)
            print "IMDB Rating : "+s+" -- "+listA[k]
            print "---------------------------------************--------------------------------------"
            print s1
            print "---------------------------------************--------------------------------------"

if(flag):
    print "Sorry, Couldn't Find Your Search! :("
