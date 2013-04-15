#!/bin/sh

make modules
cp drivers/media/video/s3c-jpeg/s3c-jpeg.ko ~/tftpboot
