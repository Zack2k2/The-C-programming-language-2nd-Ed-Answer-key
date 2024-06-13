mport matplotlib.pyplot as plt
k_constant = 8987551788

def DrawGraph(xPoints,yPoints,xlabel="X-axis",ylabel="Y-axis",tittle="Graph"):
    plt.plot(xPoints,yPoints,marker='.')
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.title(tittle)

def frange(start,end,step=1):
    while start < end:
        start+=step
        yield start

LinePointY      = lambda x,m=1,c=0 :  x*m + c
QuadraticPointY = lambda x,a=1,b=0,c=0 : a*(x**2) + b*x + c
