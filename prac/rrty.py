from groupth import *

gr = group()
gr.elements = [0,2,4,6,8]
############Functions###########################################
#validate(self,show = True):
#matrixView(self):
#extractLeftCosets(self):
#extractRightCosets(self):
##############Set group and operation here##########################
def myFunc(a,b):
    return (a+b)%10

gr.op = myFunc
gr.validate()
gr.matrixView()
gr.extractLeftCosets()
gr.extractRightCosets()
print gr

#################          ***END***           #######################
#######################################################