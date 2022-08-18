import subprocess, math
import matplotlib.pyplot as plt

#The program takes 1 min to run

#Edit the base_drop_rate, exp_required, exp_gained and whether kismets
#are used to plot the graph for the respective items

#The variables below are used for necron's handles

base_drop_rate = 0.000964
exp_required = 311284
exp_gained = 300
kismets = 1

x = []
y = []
ifile = "x.txt"
ofile = "y.txt"
file = "./drops.exe"
i=1
while(i<5000):
    i += math.ceil(i * 1/10)
    x.append(float(i))
    with open(ifile, "w") as f:
        f.write(str(i) + " " + str(base_drop_rate) + " " + str(exp_required) \
                + " " + str(exp_gained) + " " + str(kismets))
    subprocess.call([file])
    with open(ofile, "r") as f:
        tmp = f.read()
        y.append(float(tmp))
plt.plot(x, y)
plt.show()
