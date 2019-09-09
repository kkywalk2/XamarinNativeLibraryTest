#include"GpioLed.h"

int32_t GpioLed(int32_t input)
{
	char buf[BUFSIZ];
	char i = 0;
	int fd = -1;
	memset(buf, 0, BUFSIZ);

	sprintf(buf, "%d", input);
	fd = open("/dev/gpioled", O_RDWR);                /* GPIO 장치 파일을 오픈한다. */

	write(fd, buf, strlen(buf));            /* 커널 모듈에 데이터를 쓴다. */

	close(fd);                                           /* 사용이 끝난 장치 파일을 닫는다. */

	return 0;
}