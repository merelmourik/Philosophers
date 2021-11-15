##  Philosophers 

A group of philosophers is sitting at a round table either eating, thinking or sleeping. They only can do one of those thing at a time and they all only have one fork; eventhough they need two forks to eat. This means that the philosohers need to share their forks, but unfortunately there is no possibility for them to communicate with each other. The only solution is to wait till a fork is avaibale, let's just hope that it won't take too long..

The goal is that none of the philosophers dies, but sometimes there is just not enough time and one of them will die. If this happens, the simulation stops.

The program starts with the following arguments;
	- the amount of philosphers around the table.
	- the amount of milliseconds a philosopher can stay without food without dying.
	- the amount of milliseconds it takes a philosophers to eat.
	- the amound of milliseconds a philospher needs to sleep.
	- optional one; the amount of times all philosophers need to eat. It this is not specified the simulation stops when one of the philosophers dies (or, ofcourse, just use Ctrl-c).

The difference between the thee codes are the strategy they use;
	- philo_one; they can only use a fork of their neighbour, the philosophers are threads, the forks are mutexes to prevent them from duplicating forks.
	- philo_two; all the forks are in the middle of the table so they can use any fork, the philosophers are threads, the forks are semaphores to prevent them form duplicating forks.
	- philo_three; all the forks are in the middle of the table so they can use any fork, the philosophers are processes, the forks are semaphores to prevent them form duplicating forks.

All the codes have predefined examples in their makefile;
	- make surviving
	- make dying
	- make two
	- make forever