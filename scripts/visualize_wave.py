import matplotlib.pyplot as plt
from matplotlib import animation
from mpl_toolkits.mplot3d import Axes3D
import numpy as np   
import math

data = np.fromfile("../output/bin/QuantumWave.bin",dtype=float,)
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')
x = np.unique(data[:,1])
y = np.unique(data[:,2])
X, Y = np.meshgrid(x,y)
frames_data = []
def update(i):
    ax.clear()
    ax.set_zlim(0, 1)
    frame_0_indices = (data[:,0]==i) 
    z_frame_0 = data[:,3][frame_0_indices]
    Z = z_frame_0.reshape(len(x), len(y))    
    ax.plot_surface(X,Y,Z)
    
animate = animation.FuncAnimation(fig,update,frames=np.unique(data[:,0]),interval=20,blit=True)
plt.show()
