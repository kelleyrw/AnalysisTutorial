#!/usr/bin/env python

# ------------------#
# imports
# ------------------#

from optparse import OptionParser
import os
import sys

# ------------------#
# parse inputs
# ------------------#

# parameter options
parser = OptionParser()
parser.add_option("--nevts", dest="nevts", default=-1, help="REQUIRED: python configuration file")

# boolean options
parser.add_option("--verbose" , action="store_true" , dest="verbose" , default=False , help="verbose print out"                           )
parser.add_option("--test"    , action="store_true" , dest="test"    , default=False , help="test script -- print commands but do nothing")

(options, args) = parser.parse_args()

# ------------------#
# available samples 
# ------------------#

samples = [
	"dyll",
	"qcd",
]

# ---------------------------------------------------------------------------------- #
# make the babies for a particular sample
# ---------------------------------------------------------------------------------- #

def MakeBaby(sample):

	# start the command
	cmd = "create_singlelep_baby"

	# the input sample
	cmd += " --sample %s" % sample

	# number of events
	cmd += " --nevts %s" % int(options.nevts)

	# verbose	
	if (options.verbose):
		cmd += " --verbose 1"

	# logname
	log_dir_name  = "logs"
	log_file_name = "%s/%s.log" % (log_dir_name, sample)
	cmd += " >& %s &" % log_file_name
	if (not options.test and not os.path.exists(log_dir_name)):
		os.makedirs(log_dir_name)		

	if (not os.path.exists("babies")):
		os.makedirs("babies")		
	print "[create_babies_all] making babies for %s..." % (sample)
	print cmd
	if (not options.test):
		os.system(cmd)

	return	

# ------------------#
# "main program" 
# ------------------#

def main():
	try:
		# samples to run on
		for sample in samples:	
			MakeBaby(sample)

	except Exception, e:
		print "[create_babies_all] ERROR:", e
		return 1
	except:
		print "[create_babies_all] ERROR:", sys.exc_info()[0]
		return 1

# do it
if __name__ == '__main__':
	main()
