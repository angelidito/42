# Philosophers Project

This project is a simulation of the Dining Philosophers Problem, where a group of philosophers sit at a round data, alternating between eating, thinking, and sleeping. The goal is to implement the simulation in C using either threads and mutexes (mandatory part) or processes and semaphores (bonus part).

## Overview

The project consists of two programs: `philo` (mandatory part) and `philo_bonus` (bonus part).
Each program takes specific arguments and follows certain rules to simulate the behavior of the philosophers.

### Mandatory Part

In the mandatory part, the simulation should be implemented using threads and mutexes. The program should be named `philo` and should be located in the `philo/` directory. It should comply with the following requirements:

- No global variables.

- The program should take the following arguments:
  - `number_of_philosophers`: The number of philosophers (and forks), it's >= 1.
  - `time_to_die`: The time in milliseconds after which a philosopher dies if they haven't started eating.
  - `time_to_eat`: The time in milliseconds it takes for a philosopher to eat while holding two forks.
  - `time_to_sleep`: The time in milliseconds a philosopher spends sleeping.
  - `[number_of_times_each_philosopher_must_eat]` (optional): The number of times each philosopher must eat before the simulation stops (default is when a philosopher dies).

- Philosophers:
  - Loop: `sleep` -> `think` -> `eat`
  - Take forks at their left and right before eating.
  - Must be able to eat without deadlock or starvation.
  - Don’t speak with each other.
  - Don’t know if another philosopher is about to die.
  - Have a number from 1 to `number_of_philosophers`.
  - Should have their own **thread**.
- **Forks**:
  - Forks states should be protected with a mutex for each.


- Logs of the program:
  - Changes on philosopher X’s state:
    - `timestamp_in_ms X has taken a fork`
    - `timestamp_in_ms X is eating`
    - `timestamp_in_ms X is sleeping`
    - `timestamp_in_ms X is thinking`
    - `timestamp_in_ms X died`
  - Displayed state messages shouldn't be mixed up with another messages.
  - **Death announcements should be displayed in the next 10 ms after the death**.

- Program:
  - Must not have any **data races**
  - Ext. functions (mandatory part):
    - `memset`
    - `printf`
    - `malloc`
    - `free`
    - `write`
    - `usleep`
    - `gettimeofday`
    - `pthread_create`
    - `pthread_detach`
    - `pthread_join`
    - `pthread_mutex_init`
    - `pthread_mutex_destroy`
    - `pthread_mutex_lock`
    - `pthread_mutex_unlock`
  - Ext. functions (bonus part):
    - `memset`
    - `printf`
    - `malloc`
    - `free`
    - `write`
    - `fork`
    - `kill`
    - `exit`
    - `pthread_create`
    - `pthread_detach`
    - `pthread_join`
    - `usleep`
    - `gettimeofday`
    - `waitpid`
    - `sem_open`
    - `sem_close`
    - `sem_post`
    - `sem_wait`
    - `sem_unlink`

#### Things to consider
  - Check leaks with system("leaks philo")
  - Check data races with fsanitize=thread

### Bonus Part

In the bonus part, the simulation should be implemented using processes and semaphores. The program should be named `philo_bonus` and located in the `philo_bonus/` directory. It should comply with the same requirements as the mandatory part, in addition to the following:

- All the forks are placed in the middle of the data.
- The number of available forks is represented by a semaphore.
- Each philosopher becomes a separate process, with the main process not being a philosopher.


## Resources

- [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX Threads Documentation](https://pubs.opengroup.org/onlinepubs/009695399/functions/xsh_chap02_09.html)
- [POSIX Semaphores Documentation](https://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html)

Feel free to modify the README file according to your specific project requirements and add any additional information or instructions.
