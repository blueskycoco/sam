#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#define FB1 "/dev/fb1"
#define u32 unsigned int
struct s3c_fb_osd {
	u32		width;
	u32		height;
	u32		position_x;	/*video window's x psition control register*/
	u32		position_y;	/*video window's x psition control register*/
	u32		bits_per_pixel;
	u32		alpha;	/*video window's x alpha value*/
	u32		color_key;	/*video window's x color key value*/
	u32		comp_key;	/*video window's x color key value*/
};
#define S3CFB_OSD_START         _IO  ('F', 201)
#define S3CFB_OSD_STOP          _IO  ('F', 202)
#define S3CFB_OSD_CONFIG      	_IOW ('F', 203,struct s3c_fb_osd)

int main(int argc , char *argv[])
{

	struct s3c_fb_osd osd_info;
	osd_info.width=320;
	osd_info.height=240;
	osd_info.position_x=100;
	osd_info.position_y=10;
	osd_info.bits_per_pixel=16;
	osd_info.alpha=10;
	osd_info.color_key=0x00ff;
	osd_info.comp_key=0xff00;
	int fb1=open(FB1,O_RDWR);
	ioctl(fb1,S3CFB_OSD_CONFIG,&osd_info);
	printf("Begin test FB1\n");
	ioctl(fb1,S3CFB_OSD_START);
	sleep(100);
	ioctl(fb1,S3CFB_OSD_STOP);
	printf("FB1 OSD test end\n");	
	return 0;
}
