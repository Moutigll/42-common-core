import csv
import matplotlib.pyplot as plt

# Read data from CSV file
numbers = []
avgs = []
mins = []
maxs = []
with open('performance_results.csv', 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        numbers.append(int(row[0]))
        avgs.append(float(row[1]))
        mins.append(float(row[2]))
        maxs.append(float(row[3]))

# Set the figure size
plt.figure(figsize=(16, 12))  # 16 inches width, 12 inches height

# Plot the data
plt.plot(numbers, avgs, label='Average')
plt.plot(numbers, mins, label='Minimum')
plt.plot(numbers, maxs, label='Maximum')
plt.xlabel('Number of Inputs')
plt.ylabel('Instructions')
plt.title('Performance of Your push_swap')
plt.legend()
plt.grid(True)

# Add grid lines
plt.minorticks_on()
plt.grid(which='both', color='grey', linestyle='--', linewidth=0.5)

# Annotate the plot with exact instruction numbers for 100 and 500 inputs
for num in [100, 500]:
    index = numbers.index(num)
    plt.text(num, maxs[index]+100, f"Max:{maxs[index]}", ha='center', va='top', fontsize=12)
    plt.text(num, avgs[index]-100, f"Avg:{avgs[index]}", ha='center', va='bottom', fontsize=12)
    plt.text(num, mins[index]-200, f"Min:{mins[index]}", ha='center', va='bottom', fontsize=12)

# Save the plot as an image file
plt.savefig('performance_plot.png', dpi=300)

# Close the plot to free up resources
plt.close()
