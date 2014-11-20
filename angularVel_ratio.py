
import numpy as np
import matplotlib.pyplot as plt

	#constants
wf = 48
wr = 48
l= 62

def find_ratio(sigma_out, sigma_in):


	#angular velocity ratio of inner to outer wheel
	ratio_o = (sigma_out*(wf+wr)-2*l)/(sigma_out*(wf-wr)-2*l)
	ratio_i = (sigma_in*(wf+wr)-2*l)/(sigma_in*(wf-wr)-2*l)

	avg_ratio = (ratio_o + ratio_i)/2.0

	return avg_ratio

def make_plot():
	out = []
	sigma_in_li = np.linspace(0,6.2)
	sigma_out_li = []

	for i in range (0,len(sigma_in_li)):
		sigma_out_li.append(np.arctan(1/((wf/l) + np.tan(1/(sigma_in_li[i])) )) )

	for i in range(0,len(sigma_in_li)):
		out.append(find_ratio(sigma_out_li[i],sigma_in_li[i]))

	plt.plot(sigma_in_li,out)
	plt.show()
	

	# print sigma_out_li[1]
	#find_ratio(sigma_out)



if __name__ == '__main__':
	#find_ratio(.186,.209)
	make_plot()





# x = np.linspace(0, 10)
# line, = plt.plot(x, np.sin(x), '--', linewidth=2)

# dashes = [10, 5, 100, 5] # 10 points on, 5 off, 100 on, 5 off
# line.set_dashes(dashes)

# plt.show()