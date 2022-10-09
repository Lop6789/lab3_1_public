from unicodedata import decimal
import matplotlib.pyplot as plt
import csv

x = []
y = []
legend = []

with open ("../result.csv") as f:
    reader = csv.reader(f, delimiter=" ")
    legend = next(reader)[1:-1]
    #data = [row[:-1] for row in reader]
    for row in reader:
        x.append(int(row[0]))
        y.append(list(map(float, row[1:-1])))
    # x = [float(row) for row in reader]
    # print(x)
    # print(y)
    #print(legend)
    plt.plot(x, y)
    plt.title("Graph of sorts (dependence time from quantity of elements)")
    plt.grid()
    plt.xlabel("N elements")
    plt.ylabel("Time(N)")
    plt.legend(legend)
    plt.show()
    # plt.savefig

    
    


