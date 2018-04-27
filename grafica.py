import numpy as np
import matplotlib.pyplot as plt

datos=np.genfromtxt("test.txt",delimiter=" ")


n=np.shape(datos)[0]
m=int(np.sqrt(np.shape(datos)[1]))
ind=0

while ind < n:
    plt.imshow(np.transpose(datos[ind,:].reshape((m,m))))
    nombre="grafica"+str(ind)+".pdf"
    plt.savefig(nombre)
    ind+=1


