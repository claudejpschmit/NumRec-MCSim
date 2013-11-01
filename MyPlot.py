#
#  MyPlot.py
#  
#

from numpy import * ;
from matplotlib.pyplot import *;

# Read the file and convery each line into a double number
with open(sys.argv[1]) as f:
    val = [double(line) for line in f]
 
#print(val); 

# Make the histogram and show it
hist(val,50) ;
show();

