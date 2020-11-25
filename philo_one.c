#include "philo_one.h"

t_philo *validate_input(int argc, char **argv)
{
    t_philo *philo;

    philo = malloc(sizeof (t_philo));
    if (argc != 5 && argc != 6)
    {
        write(1, "Not the correct amount of arguments\n", 37);
//        free (philo);
        return philo;
    }
    philo->philo = ft_atoi(argv[1]);
    philo->die = ft_atoi(argv[2]);
    philo->eat = ft_atoi(argv[3]);
    philo->sleep = ft_atoi(argv[4]);
    if (argc == 6)
        philo->repetition = ft_atoi(argv[5]);
    if ((philo->philo == 0 || philo->die == 0 || philo->eat == 0 || philo->sleep == 0) \
        || (argc == 6 && philo->repetition == 0))
        return NULL;
    return philo;
}

int main(int argc, char **argv)
{
    t_philo philo;
    philo = *validate_input(argc, argv);
    if (!philo)
        free (philo);
    return (0);
//    printf("%d\n", philo.eat);
}