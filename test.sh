#!/bin/bash
# test script
E="./geneology.out"
function f1(){
	$E d
	echo -ne "\n" | $E i
	$E d

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

	# # test mate on a master which isn't in our tree
	# $E m 2 1 8
	# # reverse is correct
	# $E m 1 2 8
	# $E d
	# # more child
	# $E m 1 2 4
	# $E d
	# # waste
	# $E m 1 2 4 8
	# $E m 1 2 8 4
	# $E d

	# test incest
	# 
	# test child wrench
	# 

	# test attach person with wife
	# 
	# test attach person with subspring
	# 

	# $E mate 0 1 2 3
	# $E display
	# $E mate 0 1 4 5
}
# echo $(f1) | grep -v "browser"
function f2(){
	echo "hello"
	echo "yello"
}
f1 |& grep -v -F -e 'ERROR:browser_gpu_channel_host_factory.cc' -e 'Created new window in existing browser session.'