<div align="center">

![](https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/badges/philosopherse.png)

# **Philosophers**

**I never thought philosophy would be so deadly**

</div>

## Features

- Simulate the Dining Philosophers problem using multithreading.  
- Manage philosophers' states: eating, thinking, and sleeping.  
- Prevent deadlocks through proper synchronization mechanisms.  
- Use mutexes or semaphores for resource (forks) management.  
- Handle simultaneous access to shared resources safely.  
- Implement program arguments for customization (number of philosophers, time to eat, sleep, die, etc.).  
- Ensure accurate timing and behavior with minimal delays.

## Installation

1. Clone the repository:

```bash
git clone https://github.com/lanceleau02/Philosophers.git
```

2. Navigate to the project directory:

```bash
cd Philosophers
```

3. Compile the program:

```bash
make
```

## Usage

Use the following syntax to execute the program:

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

Where:

- `number_of_philosophers`: Total number of philosophers and forks.
- `time_to_die`: Time (in milliseconds) a philosopher can live without eating.
- `time_to_eat`: Time (in milliseconds) it takes for a philosopher to eat.
- `time_to_sleep`: Time (in milliseconds) a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): Number of meals required for each philosopher before the simulation ends.

## License

This project is licensed under the **42 School** License.

- **Educational Use Only**: This project is intended for educational purposes at the 42 School as part of the curriculum.
- **Non-commercial Use**: The code may not be used for commercial purposes or redistributed outside of the 42 School context.
- **No Warranty**: The project is provided "as-is", without any warranty of any kind.

For more details, see the [LICENSE](https://github.com/lanceleau02/Philosophers/blob/main/LICENSE) file.

## Resources

- [pthread_create(3) (Linux manual page)](https://man7.org/linux/man-pages/man3/pthread_create.3.html)  
- [pthread_mutex_lock(3) (Linux manual page)](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3.html)  
- [pthread_mutex_unlock(3) (Linux manual page)](https://man7.org/linux/man-pages/man3/pthread_mutex_unlock.3.html)  
- [pthread_join(3) (Linux manual page)](https://man7.org/linux/man-pages/man3/pthread_join.3.html)  
- [Semaphores in C (GeeksforGeeks)](https://www.geeksforgeeks.org/semaphores-in-process-synchronization/)  
- [Mutexes and Condition Variables (The GNU C Library)](https://www.gnu.org/software/libc/manual/html_node/Condition-Variables.html)  
- [Dining Philosophers Problem (GeeksforGeeks)](https://www.geeksforgeeks.org/dining-philosophers-problem-using-semaphores/)  
- [usleep(3) (Linux manual page)](https://man7.org/linux/man-pages/man3/usleep.3.html)  
- [time.h library (cplusplus.com)](https://cplusplus.com/reference/ctime/)  
- [Race Conditions (GeeksforGeeks)](https://www.geeksforgeeks.org/race-conditions-in-processes/)  
