#!/bin/bash
# test script
E="./geneology.out"
function f1(){
	# test mate incorrect number of paras
	$E m 1
	# test mate on root
	$E m 0 1 2
	# test mate nonexist person
	$E m 97 98 99

	# test attach nonexist person
	$E a 100
	# attach correct
	$E a 1
	$E d
}
function f2(){
	# attach nonexist member
	$E a 99

	# attach correct
	$E a 1
	$E d

	# test mate wrong order master slave
	$E m 2 1 8
	$E d 

	# test mate correct order
	$E m 1 2 8
	$E d
}
function f3(){
	# let's be serious - crunch everything 
	$E a 2
	# subspring of Gim Il-seong
	$E m 2 1 3 10 11
	# subspring of Gim Jeong-il
	$E m 3 4 13 5 6 14
	$E m 3 8 9
	# subspring of Kim Jong-un
	$E m 5 6 7
	# display
	$E d
}
function finit(){
	echo -ne "\n" | $E i
}
make clean
make geneology
# init
finit
# run
f1 |& grep -v -F -e 'ERROR:browser_gpu_channel_host_factory.cc' -e 'Created new window in existing browser session.'
# init
finit
# run
f2 |& grep -v -F -e 'ERROR:browser_gpu_channel_host_factory.cc' -e 'Created new window in existing browser session.'
# init
finit
# run
f3 |& grep -v -F -e 'ERROR:browser_gpu_channel_host_factory.cc' -e 'Created new window in existing browser session.'
