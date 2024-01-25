#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<fcntl.h>
#include<time.h>

#define POWER_SUPPLY_FILENAME		"/sys/class/power_supply/AC/online"
#define POWER_BUTTON_LED_FILENAME	"/sys/class/leds/tpacpi::power/brightness"
#define TURN_OFF                 	"0"
#define TURN_ON                  	"1"

static bool	loop=true;

void	sig_handler(int signum)
{
	printf("----\tGOT SIGINT. EXITING\t----\n");
	loop = false;
}

int	main(void)
{
	char	supply=0;
	int	led_fd, ps_fd;

	led_fd = open(POWER_BUTTON_LED_FILENAME, O_WRONLY);
	if (led_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: %s\n\tCan not open %s\n", strerror(errno), 
				POWER_BUTTON_LED_FILENAME);
		return EXIT_FAILURE;
	}
	//if (ps_fd < 0)
	//{
	//	dprintf(STDERR_FILENO, "Error: %s\n\tCan not open %s\n", strerror(errno), 
	//			POWER_SUPPLY_FILENAME);
	//	return EXIT_FAILURE;
	//}
	signal(SIGINT,sig_handler);
	while(loop)
	{
		write(led_fd, TURN_OFF, 1);
		sleep(1);
		write(led_fd, TURN_ON, 1);
		sleep(1);
		ps_fd = open(POWER_SUPPLY_FILENAME, O_RDONLY);
		read(ps_fd, &supply, 1);
		if (supply == '1')
			break ;
		close(ps_fd);
	}
	close(led_fd);
	return EXIT_SUCCESS;
}
