import matplotlib.pyplot as plt
import csv

x = []
y = []
legend = []

with open ("../result.csv") as f:
    reader = csv.reader(f, delimiter=" ")
    legend = next(reader)[1:-1]
    
    for row in reader:
        x.append(int(row[0]))
        y.append(list(map(float, row[1:-1])))

    plt.plot(x, y)
    plt.title("Graph of sorts (dependence time from quantity of elements)")
    plt.grid()
    plt.xlabel("N elements")
    plt.ylabel("Time(N)")
    plt.legend(legend)
    plt.show()

    
    


