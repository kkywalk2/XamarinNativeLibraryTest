#include"GpioLed.h"

int32_t GpioLed(int32_t input)
{
	char buf[BUFSIZ];
	char i = 0;
	int fd = -1;
	memset(buf, 0, BUFSIZ);

	sprintf(buf, "%d", input);
	fd = open("/dev/gpioled", O_RDWR);                /* GPIO ��ġ ������ �����Ѵ�. */

	write(fd, buf, strlen(buf));            /* Ŀ�� ��⿡ �����͸� ����. */

	close(fd);                                           /* ����� ���� ��ġ ������ �ݴ´�. */

	return 0;
}